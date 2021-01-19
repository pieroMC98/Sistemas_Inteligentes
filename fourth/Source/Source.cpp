#include "./Source.h"

/**
 * @brief Inicio variables estáticas
 *
 */
float Source::xmin = 1, Source::xmax = 10;
int Source::sol = 4;
Call Source::c_b = NULL;
int Source::ID = 0;

/**
 * @brief Construct a new Source:: Source object
 *
 */
Source::Source() : Particle() {
	this->limiti = 0;
	this->call_back = Source::c_b;
};

/** soluciones del array de fuentes
 * @brief fórmula que da valores a las soluciones de las fuentes
 *
 */
void Source::setArraySolve() {
	std::for_each(this->position.begin(), this->position.end(),
		      [&](float &j) { j = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin); });
}

/**
 * @brief Construct a new Source:: Source object
 *
 * @param i para las solciones de las fuentes
 */
Source::Source(float i) {
	this->id = Source::ID++;
	this->limiti = 0;
	srand(time(NULL) + this->getID() * MAX_POS);
	this->call_back = Source::c_b;
	for (auto &i : this->position) i = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin);
	this->fitness();
}

/**
 * @brief setter de la position
 *
 * @param x posición a escribir
 */
void Source::setPosition(std::vector<float> x) {
	this->position = x;
	this->value = Source::c_b(this->position, this->position.size());
}

/**
 * @brief imprimi los parámetros
 *
 */
void Source::getParameters() {
	std::cout << "fuente en la posicion (";
	for (auto x : this->position) std::cout << x << " ";
	std::cout << "\b)\nfitness = " << this->getFitness() << std::endl;
}

/**
 * @brief getter del fitness
 *
 * @return float fitness
 */
float Source::getFitness() { return this->value; }

/**
 * @brief devuelve array de soluciones
 *
 * @return std::vector<Source>
 */
std::vector<Source> Source::getArraySolve() { return this->solves_array; }

/**
 * @brief setter del array de soluciones
 *
 * @param i array de soluciones pasada por valor
 */
void Source::setArraySolve(std::vector<Source> i) { this->solves_array = i; }

/**
 * @brief uctualiza los valores del array de soluciones
 *
 */
void Source::update_arraySolve() {
	for (Source &j : this->getArraySolve()) j.fitness();
}

/**
 * @brief devuelve posicion de una fuente o alguna de sus soluciones
 *
 * @return std::vector<float>
 */
std::vector<float> Source::getPosition() { return this->position; }

/**
 * @brief ejecución de la fuente
 *
 */
void Source::run() {
	this->fitness();
	for (int i = 0; i < Source::sol; i++) this->solves_array.push_back(Source((float)this->random_float(0, 1)));
}
