#include "PSO.h"

Particle init(int i) {
	Particle *new = (Particle *)malloc(sizeof(Particle));
	new->id = i;
	new->posx = rand() % 10;
	new->posy = rand() % 10;

	new->speedx = VMIN + rand() % (VMAX - VMIN + 1);
	new->speedy = VMIN + rand() % (VMAX - VMIN + 1);

	new->b = (float *)calloc(10, sizeof(float));
	return *new;
}

float speed(Particle v, int t, int f1, int f2, int e1, int e2, float *g) {
	if (t > 1)
		return speed(v, t - 1, f1, f2, e1, e2, g) + f1 * e1 * (v.b[t] - v.x[t]) + f2 * e2 * (g[t] - v.x[t]);
	else
		return 1;
}

float position(int t, float *x, float *speed) {
	if (t > 1)
		return position(t - 1, x, speed) + speed[t - 1];
	else
		return 1;
}

void getParamenters(Particle i) {
	printf("--------------------\n");
	printf("particle %d\n", i.id);
	printf("Vx = %f, Vy = %f\nPosx = %f, PosY = %f", i.speedx, i.speedy, i.posx, i.posy);
	printf("\n--------------------");
}
