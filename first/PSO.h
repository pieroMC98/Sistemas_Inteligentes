/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#ifndef _PSO_H
#define _PSO_H
#include <cstdio>
#include <cstdlib>
#include <iostream>
#define VMAX 100
#define VMIN 1
class Particle {
       private:
	int id;
	float speedy, speedx, posy, posx;
	float *x, *b;
	static float *global;
	int counter() {
		static int id;
		return this->id = id++;
	}
       public:
	Particle();
	~Particle(){};
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

};
#endif
