#include "./frog.h"

vector<vector<Frog>> Frog::_columFrogs(2, vector<Frog>());

bool operator>(const Frog& r1, const Frog& r2) { return r1.value > r2.value ? true : false; }
bool operator<(const Frog& r1, const Frog& r2) { return r1.value < r2.value ? true : false; }
vector<float> operator+(const vector<float>& v1, const vector<float>& v2){
	if( v1.size() != v2.size() )
		return vector<float>();

	vector<float> aux(v1.size());
	for( size_t i = 0; i < v1.size(); i++) {
		aux[i] = v1[i] + v2[i];
	}
	return aux;
}
vector<float> operator-(const vector<float>& v1, const vector<float>& v2){
	if( v1.size() != v2.size() )
		return vector<float>();

	vector<float> aux(v1.size());
	for( size_t i = 0; i < v1.size(); i++) {
		aux[i] = v1[i] - v2[i];
	}
	return aux;
}

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

void Frog::best_local_value_postion(Frog best_frog) { Particle::best_value_position(best_frog); }

float Frog::enhance(Frog x) {
	float D = random_float(0, 1) * (x.best_global_value - x.value );
	return this->value + D;
}

void Frog::slf(Frog& x) {}

void Frog::local_search(Frog& best_particle,Frog &best_global_particle, Frog& worst_particle) {
	float x1 = worst_particle.enhance(best_particle);
	if (x1 > worst_particle.value) {
		worst_particle.value = x1;
	} else {
		x1 = worst_particle.value + Frog::best_global_value_from_memeplexer;
		if( x1 > worst_particle.value )
			worst_particle.value = x1;
	}
}
