#include "../first/Function/function.h"
#include "../second/Frog/frog.h"

int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;
	if (params(argv, argc, N, s, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Frog *tmp = new Frog(process, dimension, limits);
	vector<Frog> ranas(N);
	std::for_each(ranas.begin(), ranas.end(), [=](Particle &x) { x.call_back = function_option[option]; });
	Frog best_particle = ranas[0];
	best_particle.fitness();

	for (auto &x : ranas) {
		x.run(best_particle);
		// evaluar el fitness de cada particula
		x.fitness();

		// actualizar la mejor solucion personal de cada particula
		x.Set_best_personal_properties();
		x.best_particle(best_particle);

		// muestro cada particula por pantalla
		// x.getParameters();

		// actualizar la velocidad y posicion de cada particula
		x.update_speed(0.729, 2.05, 2.05);
		x.update_position();
		x.limit_test();
	}

	for_each(ranas.begin(), ranas.end(), [=](Frog x) { x.getParameters(); });
	tmp->sort(ranas);
	tmp->memeplexer(ranas);
	for_each(ranas.begin(), ranas.end(), [=](Frog x) { x.getParameters(); });
	// actualizar la mejor solucion global

	tmp->~Frog();
	return 0;
}
