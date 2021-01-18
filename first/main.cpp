/* Implementar en C++ el algoritmo PSO y aplicarlo a 3 funciones como mínimo, de
 * las definidas en la siguiente web: */
/*     https://www.sfu.ca/~ssurjano/optimization.html */

// Algoritmo optimizacion por enjambre de particulas
#include "Function/function.h"
#include "Particle/PSO.h"

int main(int argc, char *argv[]) {
	// variables que se van a usar para los valores de los parametros
	int N = 5;
	int salida = 3;
	int option = 0;
	int process, dimension, limits;

	// recibe los parametros por referencia y si no hay parametros suficientes devuelve error
	if (params(argv, argc, N, salida, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	// recibe todas las funciones para luego elegir que funcion se va a optimizar
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	// se crea Particula termporal para que el enjambre se cree con la dimension los limites y la optimizacion
	// que son variables estaticas de el objeto Particula
	//Particle *tmp = new Particle(process, dimension, limits);
	// instancio el array del enjambre
	std::vector<Particle> enjambre(N);
	// setter de la funcion call_back que se va ha usar que guarda la funcion para cada instancia de enjambre
	std::for_each(enjambre.begin(), enjambre.end(), [=](Particle &x) { x.call_back = function_option[option]; });
	// se elimina la instancia temporal por que ya no se usa
	//tmp->~Particle();

	// la mejor particula es la primera instancia del enjambre
	Particle best_particle = enjambre[0];
	// se guarda el fitness de la mejor particula
	best_particle.fitness();

	for (int i = 0; i < salida; i++) {
		for (auto &x : enjambre) {
			x.run(best_particle);
			// evaluar el fitness de cada particula
			x.fitness();

			// actualizar la mejor solucion personal de cada particula
			x.Set_best_personal_properties();
			x.best_particle(best_particle);

			// muestro cada particula por pantalla
			x.getParameters();

			// actualizar la velocidad y posicion de cada particula
			x.update_speed(0.729, 2.05, 2.05);
			x.update_position();
			x.limit_test();
		}
		// actualizar la mejor solucion global
		best_particle.best_value_position(best_particle);
		best_particle.getGlobalParameters();
		std::cout << "\n\033[1;32m################### " << i << " #############################\033[0m"
			  << std::endl;
	}
	return EXIT_SUCCESS;
}
