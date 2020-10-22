/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas

#include <algorithm>

#include "Function/function.h"
#include "Particle/PSO.h"

int main(int argc, char *argv[]) {
	int N = 5;
	int salida = 3;
	if (argc > 3) {
		N = atoi(argv[1]);
		salida = atoi(argv[2]);
	}
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	int option = select_function();
	std::vector<Particle> enjambre(N);
	std::for_each(enjambre.begin(), enjambre.end(), [=](Particle &x) { x.call_back = function_option[option]; });

	Particle best_particle = enjambre[0];
	for (int i = 0; i < salida; i++) {
		for (auto x : enjambre) {
			x.run();
			x.fitness();
			x.Set_best_personal_properties();
			x.best_particle(MAXIMIZAR, best_particle);
			x.update_speed(0.729, 2.05, 2.05);
			x.update_position();
			x.limit_test();
			x.getParameters();
			// evaluar el fitness de cada particula
			// actualizar la mejor solucion personal de cada particula
			// actualizar la mejor solucion global
			// actualizar la velocidad y posicion de cada particula
			std::cout << "la mejor particula ( ahora ) es " << best_particle.getID() << std::endl;
		}
		std::cout << "\n\033[1;32m################################################\033[0m" << std::endl;
	}
	return EXIT_SUCCESS;
}
