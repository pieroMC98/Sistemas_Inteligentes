#include "PSO.h"
int main(int argc, char *argv[]) {
	std::vector<Particle> enjambre(2);
	Particle best_particle = enjambre[0];
	/* particle[0].debug(); */
	/* for (auto particle : particle) particle.getParamenters(); */
	for (int i = 0; i < 10; i++) {
		enjambre[0].run();
		for (auto &x : enjambre) {
			// evaluar el fitness de cada particula
			// actualizar la mejor solucion personal de cada particula
			// actualizar la mejor solucion global
			// actualizar la velocidad y posicion de cada partucla
		}
	}
	return EXIT_SUCCESS;
}
