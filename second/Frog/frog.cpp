#include "./frog.h"
//template bool operator> <Frog>(const Frog &r1, const Frog &r2);
/**
 * inicializacion variables est'aticas
 *
 *
 */
vector<vector<Frog>> Frog::_columFrogs(2, vector<Frog>());
vector<float> Frog::best_global_position_from_memeplexer = {};
float Frog::best_global_value_from_memeplexer = -1;
vector<Frog> Frog::global_best = {};

/**
 * @brief
 *
 * @param v1
 * @param v2
 * @return vector<float>
 */
/* vector<float> operator-(const vector<float>& v1, const vector<float>& v2) { */
	/* if (v1.size() != v2.size()) return vector<float>(); */

	/* vector<float> aux(v1.size()); */
	/* for (size_t i = 0; i < v1.size(); i++) { */
		/* aux[i] = v1[i] - v2[i]; */
	/* } */
	/* return aux; */
/* } */

/**
 * @brief Construct a new Frog:: Frog object
 *
 */
Frog::Frog() : Particle() { Frog::best_global_position_from_memeplexer.resize(this->Dimension); }

/**
 * @brief
 *
 * @param ranas
 */
void Frog::sort(vector<Frog>& ranas) {
	for (size_t i = 1; i < ranas.size(); i++)
		if (ranas[i - 1] > ranas[i]) {
			Frog aux = ranas[i];
			ranas[i] = ranas[i - 1];
			ranas[i - 1] = aux;
		}
}

/**
 * @brief
 *
 * @param i
 */
void Frog::setMeme_id(int i) { this->meme_id = i; }

/**
 * @brief
 *
 * @return int
 */
int Frog::getMeme_id() { return this->meme_id; }

/**
 * @brief
 *
 * @param ranas
 */
void Frog::memeplexer_id(vector<Frog>& ranas) {
	for (size_t i = 0; i < ranas.size(); i++) {
		if (!(i % 2))
			ranas[i].setMeme_id(1);
		else
			ranas[i].setMeme_id(2);
	}
}

/**
 * @brief
 *
 * @param ranas
 */
void Frog::memeplexer(vector<Frog> ranas) {
	for (size_t i = 0; i < ranas.size(); i++)
		Frog::_columFrogs[ranas[i].getMeme_id() == 1 ? 0 : 1].push_back(ranas[i]);
}

void Frog::reset_meme() {
	for_each(Frog::_columFrogs.begin(), Frog::_columFrogs.end(), [=](vector<Frog>& i) { i.clear(); });
}

/**
 * @brief
 *
 * @param ranas
 * @return vector<vector<Frog>>
 */
vector<vector<Frog>> Frog::meme(vector<Frog>& ranas) {
	Frog::reset_meme();
	Frog::sort(ranas);
	Frog::memeplexer_id(ranas);
	Frog::memeplexer(ranas);
	return Frog::_columFrogs;
}

/**
 * @brief
 *
 * @return vector<Frog>
 */
vector<Frog> Frog::join_memeplexer(vector<vector<Frog>> meme) {
	Frog::_columFrogs = meme;
	/* Frog::_columFrogs[0].resize(meme[0].size()); */
	/* Frog::_columFrogs[1].resize(meme[1].size()); */
	/* cout << "))))\n"; */
	/* for_each(meme[0].begin(), meme[0].end(), [=](Frog f) { f.getParameters(); }); */
	/* getchar(); */
	vector<Frog> aux;
	for (auto i : Frog::_columFrogs)
		for (auto j : i) aux.push_back(j);
	return aux;
}

/**
 * @brief
 *
 */
void Frog::getParameters() {
	Particle::getParameters();
	cout << "memeplexer group " << this->meme_id << endl;
}

/**
 * @brief
 *
 * @param worst_particle
 */
void Frog::worst_particle(Frog& worst_particle) {
	if (this->process == MINIMIZAR)
		if (*this > worst_particle) worst_particle = *this;

	if (this->process == MAXIMIZAR)
		if (*this < worst_particle) worst_particle = *this;
}

/**
 * @brief
 *
 * @param worst_particle
 */
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

/**
 * @brief
 *
 * @return vector<float>
 */
vector<float> Frog::getposition() { return this->position; }

/**
 * @brief
 *
 * @param best_particle
 */
void Frog::best_value_position_from_memeplexer(Frog best_particle) {
	Frog::global_best.push_back(best_particle);
	Frog::sort(Frog::global_best);
	Frog i = Frog::global_best[Frog::global_best.size() - 1];
	cout << "la mejor particula es " << i.getID() << endl;

	Frog::best_global_value_from_memeplexer = i.value;
	Frog::best_global_position_from_memeplexer = i.position;
}

/**
 * @brief
 *
 * @param best_frog
 */
void Frog::best_local_value_postion(Frog best_frog) { Particle::best_value_position(best_frog); }

/**
 * @brief
 *
 * @param D
 */
void Frog::enhance(vector<float> D) {
	this->update_speed(D);
	this->update_position();
	this->fitness();
}

/**
 * @brief
 *
 * @param D
 */
void Frog::update_speed(vector<float> D) {
	int i = 0;
	std::for_each(this->speed.begin(), this->speed.end(), [&](float& v) {
		v = this->random_float(0, 1) * (D[i] - this->position[i]);
		/* if (v >= 2) v = 2; */
		/* if (v < -2) v = -2; */
		i++;
	});
}

/**
 * @brief
 *
 */
void Frog::random_position() {
	for_each(this->position.begin(), this->position.end(),
		 [this](float& x) { x = this->random_float(-this->limits, this->limits); });
}

/**
 * @brief
 *
 * @param best_particle
 * @param worst_particle
 */
void Frog::local_search(Frog best_particle, Frog& worst_particle) {
	Frog xb = worst_particle;
	Frog xg = worst_particle;
	xb.enhance(best_particle.position);
	xg.enhance(Frog::best_global_position_from_memeplexer);
	if (xb > worst_particle)
		worst_particle = xb;
	else if (xg > worst_particle)
		worst_particle = xg;
	else
		worst_particle.random_position();

	cout << "\nmejorado, ahora w fitness es " << worst_particle.value << "\n";
}