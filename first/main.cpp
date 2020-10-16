#include "PSO.h"
int main(int argc, char *argv[]) {
	std::vector<Particle> particle(2);
	Particle best_particle = particle[0];
	/* particle[0].debug(); */
	/* for (auto particle : particle) particle.getParamenters(); */
	for (int i = 0; i < 10; i++) {
		particle[0].run();
		for (auto &x : particle) {
			// evaluar el fitness de cada particula
			// actualizar la mejor soluicion personal de cada particula
			// actualziar la mejor soliucion glibal
			// actualizar la velocidad y posicion de cada partucla
		}
	}
	return EXIT_SUCCESS;
}
