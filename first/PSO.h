/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include "HEADER_H.h"
class Particle {
       private:
	int id;
	float speedy, speedx, posy, posx;
	std::vector<float> x, b, global;
	int counter() {
		static int id;
		return this->id = id++;
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

       public:
	Particle();
	~Particle() { std::cout << "\nobject deleted \n"; }
	void setSpeedX(float);
	void setSpeedY(float);
	float getSpeedX();
	float getSpeedY();

	void setPosX(float);
	void setPosY(float);
	float getPosX();
	float getPosY();

	void setX(float *);
	void setB(float *);
	void getParamenters();

	void insertOnX(float);
	float getOnX(int);

	void insertOnB(float);
	float getOnB(int);
	int getID();
	float speed(Particle v, int t, int f1, int f2, int e1, int e2, float *g);
	float position(int t, float *x, float *speed);
	int testParticle();
};
