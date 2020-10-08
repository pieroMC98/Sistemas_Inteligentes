#include "PSO.h"

int main(int argc, char *argv[]) {
	Particle *zero = (Particle *)malloc(5 * sizeof(Particle));
	for (int i = 0; i < 5; i++) zero[i] = init(i);

	getParamenters(zero[0]);
	/* v.b = (float*)realloc(v.b,(t+1)*sizeof(float)); */
	/* v.x = (float*)realloc(v.x,(t+1)*sizeof(float)); */
	free(zero);
	return 0;
}
