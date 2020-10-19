#include "HEADER_H.h"

class Particle {
       private:
	int id;
	int Dimension;
	std::vector<float> speed, position;
	std::vector<float> best_global_position, best_personal_position;
	float limits;
	float best_personal_value, value, best_global_value;

	void best_value_position(float value, std::vector<float> position) {
		static float best_value;
		static std::vector<float> best_position;
		if (!best_value || value > best_value) {
			best_value = value;
			this->best_global_value = best_value;
			this->best_global_position = position;
			std::cout << "la mejor posicion del mundo mundo para " << this->getID()
				  << " es = " << best_value << std::endl;
		}
	}
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

	int counter() {
		static int id;
		return this->id = id++;
	}

	void dimension() {
		static int Dimension;
		if (!Dimension) {
			std::cout << "Introduzca dimension del sistema\n";
			std::cin >> Dimension;
		}
		if (!this->Dimension) this->Dimension = Dimension;
	}

	float module_vector(std::vector<float>, int);

       public:
	Particle();
	Particle(int);
	~Particle() {}
	float random_float(float, float);
	Particle best_part(int, Particle);
	float fitness(std::vector<float>, int);
	std::vector<float> update_speed(float, float, float);
	std::vector<float> update_position();
	void setX(float *);
	void setB(float *);
	void getParameters();
	void test_particle(int);
	std::vector<float> limit_test();
	float getOnX(int);
	void SetBest_personal_value();
	void SetBest_personal_position(std::vector<float>);
	float getOnB(int);
	int getID();
	void run();
};
