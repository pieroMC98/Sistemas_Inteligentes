/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include <stdio.h>
#include <stdlib.h>
#define VMAX 100
#define VMIN 1
struct particle {
	int id;
	float speedx, speedy;
	float posx, posy;
	float *x, *b;
} typedef Particle;

Particle init(int);
void getParamenters(Particle i);
float speed(Particle v, int t, int f1, int f2, int e1, int e2, float *g);
float position(int t, float *x, float *speed);
