#include "PSO.h"

#include "HEADER_H.h"

/**
 * @brief Construct a new Particle:: Particle object
 *
 */
Particle::Particle() {
	Particle::counter();
	Particle::setGlobal();
	// Particle::dimension();
	this->Dimension = 2;
	srand(time(NULL));
	this->speed.resize(this->Dimension);
	this->position.resize(this->Dimension);

	std::for_each(this->position.begin(), this->position.end(),
		      [](float &x) { x = -VMAX + rand() % (VMAX + VMAX + 1); });
}

float Particle::getOnX(int i) { return this->x[i]; }

float Particle::getOnB(int i) { return this->b[i]; }

int Particle::getID() { return this->id; }

/**
 * @brief actualiza la velocidad de la partícula
 *
 * @param w innercia
 * @param f1 parámentro cognitivo
 * @param f2 parámetro social
 * @return std::vector<float> velocidad actualizada
 */
std::vector<float> Particle::update_speed(float w, float f1, float f2) {
	int i = 0;
	std::for_each(this->speed.begin(), this->speed.end(), [&](float &v) {
		v = w * v + f1 * (rand() % 2) * (this->best - this->position[i]) +
		    f2 * (rand() % 2) * (this->global[i] - this->position[i]);
		i++;
	});
	return this->speed;
}

/**
 * @brief actualiza la posición de la partícula
 *
 * @return std::vector<float> posición actualizada
 */
std::vector<float> Particle::update_position() {
	int j = 0;
	std::for_each(this->position.begin(), this->position.end(), [&](float &x) { x += this->speed[j++]; });
	return this->position;
}

/**
 * @brief ejecuta la partícula
 *
 */
void Particle::run() {
	std::vector<float> s = this->position;
	/* s = {1, 2}; */
	std::for_each(s.begin(), s.end(), [](float x) { std::cout << " vect = " << x << std::endl; });

	std::cout << "----" << std::endl;
	float solve = this->fitness(this->position, this->Dimension - 1);
	std::for_each(s.begin(), s.end(), [](float x) { std::cout << " vect = " << x << std::endl; });
	getchar();
	/* float solve = fitness(std::vector<float>(), 4); */
	this->speed = update_speed(0.729, 2.05, 2.05);
	this->position = update_position();
}

/**
 * @brief función objetivo de la partícula (función esfera)
 *
 * @param x vector posición de la partícula
 * @param i condición de salida de la llamada recursiva
 * @return float dominio de la función
 */
float Particle::fitness(std::vector<float> x, int i) {
	if (i > 0)
		return fitness(x, i - 1) + pow(x[i], 2);
	else
		return pow(x[i], 2);
}

void Particle::test_particle(int i) {
	for (int j = 0; j < i; j++)
		std::for_each(this->position.begin(), this->position.end(), [](float &x) { x *= x * x; });
}

Particle Particle::limit_test() {
	std::for_each(this->position.begin(), this->position.end(), [this](float &x) { if (x <) });
	return *this;
}
/**
 * @brief mejor valor de la partícula
 *
 * @param process optimización de la función(MAXIMIZAR | MINIMIZAR)
 * @param zero partícula a comparar
 * @return Particle la mejor partícula
 */
Particle Particle::best_part(int process, Particle zero) {
	Particle *best_particle = this;
	if (process == MINIMIZAR)
		if (zero.value < best_particle->value) return zero;

	if (process == MINIMIZAR)
		if (zero.value > best_particle->value) return zero;
	return *this;
}

/**
 * @brief módulo del vector de dimensión i
 *
 * @param v vector
 * @param i dimensión del vector
 * @return float módulo del vector
 */
float Particle::module_vector(std::vector<float> v, int i) {
	if (i > 0)
		return pow(module_vector(v, i - 1), 2) + pow(v[i], 2);
	else
		return v[i];
}

/**
 * @brief imprime las propiedades de la partícula
 *
 */
void Particle::getParameters() {
	int j = 0;
	std::cout << "--------------------\n";
	std::cout << "particle " << this->getID() << "\n";
	for (auto i : this->position) {
		std::cout << "pos " << j << " = " << i << std::endl;
		++j;
	}
	j = 0;
	for (auto i : this->speed) {
		std::cout << "V " << j << " = " << i << std::endl;
		++j;
	}

	std::cout << "global array == \n";
	std::for_each(this->global.begin(), this->global.end(), [](float i) { std::cout << "v = " << i << std::endl; });
	std::cout << "\n--------------------";
}
