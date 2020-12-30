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
	for (size_t i = 0; i < ranas.size(); i++) ranas[i].setMeme_id(!(i % 2) ? 1 : 2);
}

void Frog::memeplexer(vector<Frog> ranas) {
	for (size_t i = 0; i < ranas.size(); i++)
		Frog::_columFrogs[ranas[i].getMeme_id() == 1 ? 0 : 1].push_back(ranas[i]);
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
	// cout<<" la mejor particula es "<<Frog::global_best[ global_best.size() -1 ].getID();

	Frog::best_global_value_from_memeplexer = i->value;
	Frog::best_global_position_from_memeplexer = i->position;
}

void Frog::best_local_value_postion(Frog best_frog) { Particle::best_value_position(best_frog); }

float Frog::enhance(Frog x) {
	float D = random_float(0, 1) * (x.best_global_value - this->value);
	return this->value + D;
}


void Frog::update_speed(float w, float f1, float f2 ) {
	int i = 0;
	std::for_each(this->speed.begin(), this->speed.end(), [&](float &v) {
		


		v = w * v + f1 * (this->random_float(0, 1)) * (this->best_personal_position[i] - this->position[i]) +
		    f2 * (this->random_float(0, 1)) * (this->best_global_position[i] - this->position[i]);
		if (v >= 2) v = 2;
		if (v < -2) v = -2;
		i++;
	});

}
float Frog::enhance_global() {
	float D = random_float(0, 1) * (Frog::best_global_value_from_memeplexer - this->value);
	return this->value + D;
}
void Frog::slf(Frog& x) {}

void Frog::local_search(Frog& best_particle, Frog& worst_particle) {
	float x1 = worst_particle.enhance(best_particle);
	if (x1 > worst_particle.value) {
		worst_particle.value = x1;
	} else {
		float x1 = worst_particle.enhance_global();
		if (x1 > worst_particle.value) worst_particle.value = x1;
	}
}
