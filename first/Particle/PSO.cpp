#include "PSO.h"

/**
 * @brief Construct a new Particle:: Particle object
 *
 */
Particle::Particle() {
	Particle::counter();
	Particle::setProcess();
	srand(time(NULL) + this->getID() * MAX_POS);
	Particle::dimension();
	best_personal_value = value = 0;

	Particle::limit();
	this->best_global_position.resize(this->Dimension);
	this->best_personal_position.resize(this->Dimension);
	this->speed.resize(this->Dimension);
	this->position.resize(this->Dimension);

	std::for_each(this->position.begin(), this->position.end(),
		      [this](float &x) { x = this->random_float(-this->limits, this->limits); });
	std::fill(this->speed.begin(), this->speed.end(), 0);
}

/**
 * @brief Construct a new Particle:: Particle object
 *
 * @params p optimizaci'on de la particula
 * @params d dimensión del sistema
 * @params l limite de la particula
 */
Particle::Particle(int p, int d, int l) {
	this->process = p;
	this->Dimension = d;
	this->limits = l;
	Particle::dimension();
	Particle::setProcess();
	Particle::limit();
}

/**
 * @brief genera números aleatorios flotantes
 *
 * @param x límite inferior del número a generar
 * @param y límite superior del número a generar
 * @return float número generado
 */
float Particle::random_float(float x, float y) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = y - x;
	float r = random * diff;
	return x + r;
}

/**
 * @brief getter de id
 *
 * @return int devuelve id
 */
int Particle::getID() { return this->id; }

/**
 * @brief ejecuta la partícula
 *
 */
void Particle::run(Particle best_particle) {
	this->best_global_position = best_particle.best_global_position;
	this->best_global_value = best_particle.best_global_value;

	this->aux_value = this->value;
}

/**
 * @brief valor del fitness de la partícula
 *
 */
void Particle::fitness() { this->value = this->call_back(this->position, this->Dimension - 1); }

/**
 * @brief setter del mejor valor de la partícula
 *
 */
void Particle::SetBest_personal_value() {
	if (this->aux_value != 0) {
		if (this->process == MAXIMIZAR)
			if (this->value > this->best_personal_value) this->best_personal_value = this->value;

		if (this->process == MINIMIZAR)
			if (this->value < this->best_personal_value) this->best_personal_value = this->value;
	} else
		this->best_personal_value = this->value;
}

/**
 * @brief setter de la mejor posición de la partícula
 *
 * @param aux_pos vector a guardar en el objeto
 */
void Particle::SetBest_personal_position(std::vector<float> aux_pos) { this->best_personal_position = aux_pos; }

/**
 * @brief actualiza lo mejores valroes de las partículas
 *
 */
void Particle::Set_best_personal_properties() {
	SetBest_personal_value();
	if (this->aux_value != 0) {
		if (this->process == MAXIMIZAR)
			SetBest_personal_position((this->value > this->aux_value ? this->position : this->aux_pos));

		if (this->process == MINIMIZAR)
			SetBest_personal_position((this->value < this->aux_value ? this->position : this->aux_pos));
	} else
		SetBest_personal_position(this->position);
}

/**
 * @brief actualiza la velocidad de la partícula
 *
 * @param w innercia
 * @param f1 parámentro cognitivo
 * @param f2 parámetro social
 * @return std::vector<float> velocidad actualizada
 */
void Particle::update_speed(float w, float f1, float f2) {
	int i = 0;
	std::for_each(this->speed.begin(), this->speed.end(), [&](float &v) {
			v = w * v + f1 * (this->random_float(0, 1)) * (this->best_personal_position[i] - this->position[i]) +
					f2 * (this->random_float(0, 1)) * (this->best_global_position[i] - this->position[i]);
		i++;
		});
}

/**
 * @brief actualiza la posición de la partícula
 *
 * @return std::vector<float> posición actualizada
 */
void Particle::update_position() {
	int j = 0;
	this->aux_pos = this->position;
	std::for_each(this->position.begin(), this->position.end(), [&](float &x) { x += this->speed[j++]; });
	this->limit_test(this->position);
}

/**
 * @brief función objetivo de la partícula (función esfera)
 *
 * @param x vector posición de la partícula
 * @param i condición de salida de la llamada recursiva
 * @return float dominio de la función
 */
float Particle::sphere(std::vector<float> x, int i) {
	if (i > 0)
		return sphere(x, i - 1) + pow(x[i], 2);
	else
		return pow(x[i], 2);
}

/**
 * @brief test de prueba iterativa
 *
 * @param i condición de salida
 */
void Particle::test_particle(int i) {
	for (int j = 0; j < i; j++)
		std::for_each(this->position.begin(), this->position.end(), [](float &x) { x *= x * x; });
}

/**
 * @brief comprueba que la part'icula no se pase de los límites.
 *
 * @return std::vector<float> devuelve vector comprobado
 */
std::vector<float> Particle::limit_test(std::vector<float> test) {
	std::for_each(test.begin(), test.end(), [this](float &x) {
		int neg = false;
		if (x < 0) neg = true;
		if (abs(x) > this->limits) {
			x = this->limits;

		}
		if (neg == true) x *= -1;
	});

	return this->position;
}

/**
 * @brief mejor valor de la partícula
 *
 * @param process optimización de la función(MAXIMIZAR | MINIMIZAR)
 * @param best_particle actualiza la mejor partícula
 */
void Particle::best_particle(Particle &best_particle) {
	if (this->process == MINIMIZAR)
		if (this->value < best_particle.value) best_particle = *this;

	if (this->process == MAXIMIZAR)
		if (this->value > best_particle.value) best_particle = *this;
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
	std::cout << "\033[1;31m--------------------------------------\033[0m";
	std::cout << "\n\033[1;35mParticle " << this->getID() << "\033[0m\n";
	std::cout << "best personal value " << this->best_personal_value << " & personal value = " << this->value
		  << "\n";
	std::cout << "position: (";
	for (int i = 0; i < this->Dimension; i++) std::cout << this->position[i] << " ";

	std::cout << "\b)\nspeed: (";
	for (int i = 0; i < this->Dimension; i++) std::cout << this->speed[i] << " ";

	std::cout << "\b)\nbest personal position: (";
	for (int i = 0; i < this->Dimension; i++) std::cout << this->best_personal_position[i] << " ";
	std::cout << "\b)\n";
}

void Particle::getGlobalParameters() {
	std::cout << "\033[1;34m--------------------------------------\033[0m";
	std::cout << "\n\033[1;35mBest Particle = " << this->getID() << "\033[0m\n";
	std::cout << "best global value " << this->best_global_value << "\n";
	std::cout << "position: (";
	for (int i = 0; i < this->Dimension; i++) std::cout << this->position[i] << " ";
	std::cout << "\b)\n";
}
