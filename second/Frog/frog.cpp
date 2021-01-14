#include "./frog.h"

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
 * @brief Construct a new Frog:: Frog object
 *
 */
Frog::Frog() : Particle() { Frog::best_global_position_from_memeplexer.resize(this->Dimension); }

/**
 * @brief Ordena las ranas pasadas como parámetros por referencia
 *
 * @param ranas array de N ranas pasadas por referencia
 */
void Frog::sort(vector<Frog>& ranas) {
	for (size_t i = 0; i < ranas.size(); i++)
		for (size_t j = 0; j < ranas.size() - 1; j++)
			if (ranas[j] > ranas[j+1]) {
				Frog aux = ranas[j];
				ranas[j] = ranas[j + 1];
				ranas[j + 1] = aux;
			}
}

/**
 * @brief Setter del id del memeplexer
 *
 * @param i id a settear
 */
void Frog::setMeme_id(int i) { this->meme_id = i; }

/**
 * @brief Getter del id del memeplexer

 *
 * @return int
 */
int Frog::getMeme_id() { return this->meme_id; }

/**
 * @brief Establece el id de cada rana
 *
 * @param ranas array de ranas a establecer el id
 */
void Frog::memeplexer_id(vector<Frog>& ranas) {
	for (size_t i = 0; i < ranas.size(); i++)
		if (!(i % 2))
			ranas[i].setMeme_id(1);
		else
			ranas[i].setMeme_id(2);
}

/**
 * @brief Array de MxN donde M es la fila de memeplexer totales y N es cada rana de ese memeplexer
 *
 * @param ranas array de ranas a establecer en array MxN
 */
void Frog::memeplexer(vector<Frog> ranas) {
	for (size_t i = 0; i < ranas.size(); i++)
		Frog::_columFrogs[ranas[i].getMeme_id() == 1 ? 0 : 1].push_back(ranas[i]);
}

/**
 * @brief Reinicia el array MxN de memeplexer
 *
 */
void Frog::reset_meme() {
	for_each(Frog::_columFrogs.begin(), Frog::_columFrogs.end(), [=](vector<Frog>& i) { i.clear(); });
}

/**
 * @brief Crea los memeplexer
 *
 * @param ranas array de ranas a ordenar y dar id a cada una
 * @return vector<vector<Frog>> devuelve array MxN de el array N de ranas para trabajar mejor los datos
 */
vector<vector<Frog>> Frog::meme(vector<Frog>& ranas) {
	Frog::reset_meme();
	Frog::sort(ranas);
	Frog::memeplexer_id(ranas);
	Frog::memeplexer(ranas);
	return Frog::_columFrogs;
}

/**
 * @brief Recibe array MxN y transforma a array M
 *
 * @return vector<Frog> array M
 */
vector<Frog> Frog::join_memeplexer(vector<vector<Frog>> meme) {
	Frog::_columFrogs = meme;
	vector<Frog> aux;
	for (auto i : Frog::_columFrogs)
		for (auto j : i) aux.push_back(j);
	return aux;
}

/**
 * @brief Obtener propiedades de cada rana
 *
 */
void Frog::getParameters() {
	Particle::getParameters();
	cout << "memeplexer group " << this->meme_id << endl;
}

/**
 * @brief Establece la peor rana
 *
 * @param worst_particle peor rana pasada por referencia
 */
void Frog::worst_particle(Frog& worst_particle) {
	if (this->process == MINIMIZAR)
		if (*this > worst_particle) worst_particle = *this;

	if (this->process == MAXIMIZAR)
		if (*this < worst_particle) worst_particle = *this;
}

/**
 * @brief Establece la peor posicion de la peor rana
 *
 * @param worst_particle recibe peor rana
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

	this->worst_global_value = worst_value;
	this->worst_global_position = worst_position;
}

/**
 * @brief Getter de la posición de la rana
 *
 * @return vector<float>
 */
vector<float> Frog::getposition() { return this->position; }

/**
 * @brief Obtener la mejor rana global
 *
 * @param best_particle mejor rana a procesar
 */
void Frog::best_value_position_from_memeplexer(Frog best_particle) {
	Frog::global_best.push_back(best_particle);
	Frog::sort(Frog::global_best);
	Frog i;
	if (best_particle.process == MAXIMIZAR)
		i = Frog::global_best.back();
	else
		i = Frog::global_best.front();
	cout << "la mejor particula global es " << i.getID() << endl;

	Frog::best_global_value_from_memeplexer = i.value;
	Frog::best_global_position_from_memeplexer = i.position;
}

/**
 * @brief Obtener la mejor rana local del memeplexer i
 *
 * @param best_frog recibe la mejor rana
 */
void Frog::best_local_value_postion(Frog best_frog) { Particle::best_value_position(best_frog); }

/**
 * @brief mejora una rana
 *
 * @param D posición de mejora
 */
void Frog::enhance(vector<float> D) {
	this->update_speed(D);
	this->update_position();
	this->limit_test();
	this->fitness();
}

/**
 * @brief velocidad de la rana
 *
 * @param D posición de mejora
 */
void Frog::update_speed(vector<float> D) {
	int i = 0;
	std::for_each(this->speed.begin(), this->speed.end(), [&](float& v) {
		v = this->random_float(0, 1) * (D[i] - this->position[i]);
		i++;
	});
}

/**
 * @brief Si la rana no mejora, dar valores aleatorios
 *
 */
void Frog::random_position() {
	for_each(this->position.begin(), this->position.end(),
		 [this](float& x) { x = this->random_float(-this->limits, this->limits); });
	this->fitness();
}

/**
 * @brief búsqueda local de la peor partícula a mejorar. Si la peor rana mejora más que la mejor rana
 *, esta se convertirá en la mejora rana
 *
 * @param best_particle mejor rana pasada por referenicia por si hay que actualizar
 * @param worst_particle recibe la peor rana a actualizar
 */
void Frog::local_search(Frog& best_particle, Frog& worst_particle) {
	Frog xb = worst_particle;
	Frog xg = worst_particle;
	xb.enhance(best_particle.position);
	xg.enhance(Frog::best_global_position_from_memeplexer);
	if (best_particle.process == MAXIMIZAR) {
		if (xb > worst_particle)
			worst_particle = xb;
		else if (xg > worst_particle)
			worst_particle = xg;
		else
			worst_particle.random_position();
	} else {
		if (xb < worst_particle)
			worst_particle = xb;
		else if (xg < worst_particle)
			worst_particle = xg;
		else
			worst_particle.random_position();
	}
}