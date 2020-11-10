/* Implementar en C el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include "Function/function.h"
#include "Particle/PSO.h"

int main(int argc, char *argv[]) {
	int N = 5;
	int salida = 3;
	int option = 0;
	int process, dimension, limits;
	if (params(argv, argc, N, salida, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Particle *tmp = new Particle(process, dimension, limits);
	std::vector<Particle> enjambre(N);
	std::for_each(enjambre.begin(), enjambre.end(), [=](Particle &x) { x.call_back = function_option[option]; });
	tmp->~Particle();

	Particle best_particle = enjambre[0];
	best_particle.fitness();

	for (int i = 0; i < salida; i++) {
		for (auto &x : enjambre) {
			x.run(best_particle);
			x.fitness();
			x.Set_best_personal_properties();
			x.best_particle(best_particle);

			x.getParameters();
			x.update_speed(0.729, 2.05, 2.05);
			x.update_position();
			x.limit_test();
			// evaluar el fitness de cada particula
			// actualizar la mejor solucion personal de cada particula
			// actualizar la mejor solucion global
			// actualizar la velocidad y posicion de cada particula
			std::cout << "la mejor particula ( ahora ) es " << best_particle.getID() << std::endl;
		}
		best_particle.best_value_position(best_particle);
		std::cout << "\n\033[1;32m################################################\033[0m" << std::endl;
	}
	return EXIT_SUCCESS;
}
