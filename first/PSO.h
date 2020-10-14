/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include "HEADER_H.h"
class Particle {
       private:
	int id;
	int Dimension;
	std::vector<float> speed, position;
	std::vector<float> x, b, global;
	float best_pos, best_value, value;
	int counter() {
		static int id;
		return this->id = id++;
	}
	
	void dimension(){
		static int Dimension;
		if( !Dimension ){
			std::cout<<"Introduzca dimension del sistema\n";
			std::cin>>Dimension;
		}
		if( !this->Dimension ) this->Dimension = Dimension;
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

	float module_vector(std::vector<float>,int);
       public:
	Particle();
	Particle(int);
	~Particle() {}
	void setSpeedX(float);
	void setSpeedY(float);
	Particle best_part(int);
	float target_function(std::vector<float>,int);
	void setX(float *);
	void setB(float *);
	void getParamenters();

	void insertOnX(float);
	float getOnX(int);

	void insertOnB(float);
	float getOnB(int);
	int getID();
	float speed_test(int , int , int , int , int , float *);
	std::vector<float> test_particle();
	float pos_test(int , float *, float *);
	int testParticle(int,int);
};
