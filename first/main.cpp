/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include <vector>
#include "PSO.h"
int suma(int a, int b) {
	return a + b;
}

float esfera(std::vector<float> x, int i) {
	if (i > 0)
		return esfera(x, i - 1) + pow(x[i], 2);
	else
		return pow(x[i], 2);

}
int main(int argc, char *argv[]) {
	int N = 3;
	int salida = 10;
	if (argc > 3) {
		N = atoi(argv[1]);
		salida = atoi(argv[2]);
	}

	std::vector<Particle> enjambre(N);
	std::for_each(enjambre.begin(), enjambre.end(), [=](Particle &x) { x.call_back = esfera; });

	Particle *best_particle = &enjambre[0];
	for (int i = 0; i < 3; i++) {
		for (auto &x : enjambre) {
			x.run();
			x.best_part(MAXIMIZAR, *best_particle);
			x.getParameters();
			// evaluar el fitness de cada particula
			// actualizar la mejor solucion personal de cada particula
			// actualizar la mejor solucion global
			// actualizar la velocidad y posicion de cada partucla
		}
		std::cout << "\n\033[1;32m################################################\033[0m" << std::endl;
	}
	return EXIT_SUCCESS;
}
