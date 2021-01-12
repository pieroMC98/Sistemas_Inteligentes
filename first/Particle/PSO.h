#include "../../HEADER_H.h"
#ifndef _PARTICLE_H
#define _PARTICLE_H
class Particle {
       protected:
	int id;
	int Dimension, process;
	std::vector<float> speed, position, aux_pos;
	std::vector<float> best_global_position, best_personal_position;
	float limits;
	float best_personal_value, value, best_global_value;
	float aux_value;

	/**
	 * @brief Set el tipo de optimización para todas las partículas
	 *
	 */
	void setProcess() {
		static int process;
		if (this->process != 0) process = this->process;
		if (!process) {
			std::string option;
			std::cout << "MINIMIZAR(1) | MAXIMIZAR(2)\n";
			std::getline(std::cin, option);
			process = atoi(option.c_str());
		}
		this->process = process;
	}

	/**
	 * @brief genera los límites de las partículas
	 *
	 */
	void limit() {
		static float LIMIT;
		if (this->limits != 0) LIMIT = this->limits;
		if (!LIMIT) {
			std::string op;
			std::cout << "\033[1;33mIntroduzca los limites o por defecto = 1000 (skip)\033[0m" << std::endl;
			std::getline(std::cin, op);
			LIMIT = atoi(op.c_str()) == 0 ? MAX_POS : atoi(op.c_str());
		}
		this->limits = LIMIT;
	}

	/**
	 * @brief id único para cada partícula
	 *
	 */
	void counter() {
		static int id;
		this->id = id++;
	}

	/**
	 * @brief espacio vectorial por el cual se vana desplazar las partículas
	 *
	 */
	void dimension() {
		static int Dimension;
		if (this->Dimension != 0) Dimension = this->Dimension;
		if (!Dimension) {
			std::string n;
			std::cout << "Introduzca dimension del sistema\n";
			std::getline(std::cin, n);
			Dimension = atoi(n.c_str());
		}
		if (!this->Dimension) this->Dimension = Dimension;
	}

	float random_float(float, float);
	float sphere(std::vector<float>, int);
	void test_particle(int);
	void SetBest_personal_value();
	void SetBest_personal_position(std::vector<float>);
	float module_vector(std::vector<float>, int);

       public:
	Particle(int, int, int);
	Particle();
	~Particle() {}
	void run(Particle);
	void fitness();
	void Set_best_personal_properties();
	void best_particle(Particle &);
	virtual void getParameters();
	void getGlobalParameters();
	virtual void update_speed(float, float, float);
	void update_position();
	int getID();
	void limit_test();
	float (*call_back)(std::vector<float>, int);

	/**
	 * @brief
	 *
	 * @param best_particle
	 */
	void best_value_position(Particle &best_particle) {
		float value = best_particle.value;
		std::vector<float> position = best_particle.position;
		static float best_value;
		static std::vector<float> best_position;

		if (best_value != 0) {
			if (this->process == MAXIMIZAR)
				if (value > best_value) {
					best_value = value;
					best_position = position;
				}

			if (this->process == MINIMIZAR)
				if (value < best_value) {
					best_value = value;
					best_position = position;
				}
		} else {
			best_value = value;
			best_position = position;
		}

		// esto no es est'atico
		this->best_global_value = best_value;
		this->best_global_position = best_position;
	}
};
#endif
