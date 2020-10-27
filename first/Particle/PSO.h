#include "../HEADER_H.h"

class Particle {
       private:
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
		if (!Dimension) {
			std::string n;
			std::cout << "Introduzca dimension del sistema\n";
			std::getline(std::cin, n);
			Dimension = atoi(n.c_str());
		}
		if (!this->Dimension) this->Dimension = Dimension;
	}

       public:
	Particle();
	Particle(int);
	~Particle() {}
	float random_float(float, float);
	void best_particle(Particle &);
	float sphere(std::vector<float>, int);
	void fitness();
	void Set_best_personal_properties();
	void update_speed(float, float, float);
	void update_position();
	void getParameters();
	void test_particle(int);
	std::vector<float> limit_test();
	void SetBest_personal_value();
	void SetBest_personal_position(std::vector<float>);
	int getID();
	float module_vector(std::vector<float>, int);
	void run(Particle);
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
