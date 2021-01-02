#include "./frog.h"

vector<vector<Frog>> Frog::_columFrogs(2, vector<Frog>());
vector<float> Frog::best_global_position_from_memeplexer = {};
float Frog::best_global_value_from_memeplexer = -1;
vector<Frog> Frog::global_best = {};

bool operator>(const Frog& r1, const Frog& r2) { return r1.value > r2.value ? true : false; }
bool operator<(const Frog& r1, const Frog& r2) { return r1.value < r2.value ? true : false; }
vector<float> operator+(const vector<float>& v1, const vector<float>& v2) {
	if (v1.size() != v2.size()) return vector<float>();

	vector<float> aux(v1.size());
	for (size_t i = 0; i < v1.size(); i++) {
		aux[i] = v1[i] + v2[i];
	}
	return aux;
}

vector<float> operator-(const vector<float>& v1, const vector<float>& v2) {
	if (v1.size() != v2.size()) return vector<float>();

	vector<float> aux(v1.size());
	for (size_t i = 0; i < v1.size(); i++) {
		aux[i] = v1[i] - v2[i];
	}
	return aux;
}

Frog::Frog() : Particle() { Frog::best_global_position_from_memeplexer.resize(this->Dimension); }

void Frog::sort(vector<Frog>& ranas) {
	for (size_t i = 1; i < ranas.size(); i++)
		if (ranas[i - 1] > ranas[i]) {
			Frog aux = ranas[i];
			ranas[i] = ranas[i - 1];
			ranas[i - 1] = aux;
		}
}

void Frog::setMeme_id(int i) { this->meme_id = i; }

int Frog::getMeme_id() { return this->meme_id; }

void Frog::memeplexer_id(vector<Frog>& ranas) {
	for (size_t i = 0; i < ranas.size(); i++) {
		if (!(i % 2))
			ranas[i].setMeme_id(1);
		else
			ranas[i].setMeme_id(2);
	}
}

void Frog::memeplexer(vector<Frog> ranas) {
	for (size_t i = 0; i < ranas.size(); i++)
		Frog::_columFrogs[ranas[i].getMeme_id() == 1 ? 0 : 1].push_back(ranas[i]);
}

vector<vector<Frog>> Frog::meme(vector<Frog>& ranas) {
	Frog::sort(ranas);
	Frog::memeplexer_id(ranas);
	Frog::memeplexer(ranas);
	return Frog::_columFrogs;
}

void Frog::getParameters() {
	Particle::getParameters();
	cout << "memeplexer group " << this->meme_id << endl;
}

void Frog::worst_particle(Frog& worst_particle) {
	if (this->process == MINIMIZAR)
		if (*this > worst_particle) worst_particle = *this;

	if (this->process == MAXIMIZAR)
		if (*this < worst_particle) worst_particle = *this;
}

void Frog::worst_value_position(Frog& worst_particle) {
	float value = worst_particle.value;
	std::vector<float> position = worst_particle.position;
	static float worst_value;
	static std::vector<float> worst_position;

	if (worst_value != 0) {
		if (this->process == MAXIMIZAR)
			if (value < worst_value) {
				worst_value = value;
				worst_position = position;
			}

		if (this->process == MINIMIZAR)
			if (value > worst_value) {
				worst_value = value;
				worst_position = position;
			}
	} else {
		worst_value = value;
		worst_position = position;
	}

	// esto no es est'atico
	this->worst_global_value = worst_value;
	this->worst_global_position = worst_position;
}

void Frog::best_value_position_from_memeplexer(Frog best_particle) {
	Frog::global_best.push_back(best_particle);
	Frog::sort(Frog::global_best);
	vector<Frog>::iterator i = Frog::global_best.end();
	cout << " la mejor particula es " << i->getID();

	Frog::best_global_value_from_memeplexer = i->value;
	Frog::best_global_position_from_memeplexer = i->position;
	cout << i->position[0];
	//cout << Frog::global_best[0].position[0];
	getchar();
}

void Frog::best_local_value_postion(Frog best_frog) { Particle::best_value_position(best_frog); }

Frog Frog::enhance(float w, float f1, float f2, vector<float> D) {
	this->update_speed(w, f1, f2, D);
	this->update_position();
	this->fitness();
	return *this;
}

void Frog::update_speed(float w, float f1, float f2, vector<float> D) {
	int i = 0;
	std::for_each(this->speed.begin(), this->speed.end(), [&](float& v) {
		v = this->random_float(0, 1) * (D[i] - this->position[i]);
		if (v >= 2) v = 2;
		if (v < -2) v = -2;
		i++;
	});
}

void Frog::local_search(Frog& best_particle, Frog& worst_particle, float w, float f1, float f2) {
	Frog xb = worst_particle.enhance(w, f1, f2, best_particle.position);
	Frog xg = worst_particle.enhance(w, f1, f2, Frog::best_global_position_from_memeplexer);
	if (xb > worst_particle) {
		worst_particle = xb;
	} else {
		if (xg > worst_particle) worst_particle = xg;
	}
}
