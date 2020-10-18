/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include <cstdio>
#include <cstdlib>
#include "HEADER_H.h"
class Particle {
       private:
	int id;
	int Dimension;
	std::vector<float> speed, position;
	std::vector<float> x, b, global, limits;
	float best;
	float best_pos, best_value, value;
	void limit() {
		static std::vector<float> LIMIT(this->Dimension);
		bug;
		if (!LIMIT[0]) {
		float option;
		std::string op;
			std::cout << " introduzca los limites o por defecto = 1000 (skip)" << std::endl;
			std::getline(std::cin, op);
			option = atoi(op.c_str())== 0?1000:atoi(op.c_str());
			std::for_each(LIMIT.begin(), LIMIT.end(), [&](float &x) { 
					x = option; 
			});
			this->limits = LIMIT;
		}
		std::cout << " limit en primera" << LIMIT[0] << std::endl;
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
	Particle limit_test();
	float getOnX(int);
	float getOnB(int);
	int getID();
	void run();
};
