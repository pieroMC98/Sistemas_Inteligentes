/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include "HEADER_H.h"

class Particle {
       private:
	int id;
	int Dimension;
	std::vector<float> speed, position, best_personal_position;
	std::vector<float> x, b, global;
	float best, limits;
	float best_personal_value, value;

	void best_value_position(float value, std::vector<float> position) {
		static float best_value;
		static std::vector<float> best_position;
		if (!best_value) {
			best_value = value;
			best_position = position;
		}
	}
	void limit() {
		static float LIMIT;
		if (!LIMIT) {
			std::string op;
			std::cout << " introduzca los limites o por defecto = 1000 (skip)" << std::endl;
			std::getline(std::cin, op);
			LIMIT = atoi(op.c_str()) == 0 ? 1000 : atoi(op.c_str());
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
	std::vector<float> setGlobal(float x) {
		static std::vector<float> global;
		global.push_back(x);
		return this->global = global;
	}

	std::vector<float> setGlobal() {
		static std::vector<float> global;
		for (int i = 0; i < 5; i++) global.push_back(rand() % 10);
		return this->global = global;
	}

	float module_vector(std::vector<float>, int);

       public:
	Particle();
	Particle(int);
	~Particle() {}
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
	float getOnB(int);
	int getID();
	void run();
};
