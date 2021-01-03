#include "../first/Function/function.h"
#include "../second/Frog/frog.h"

int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;
	typedef vector<Frog> _rowFrogs;
	vector<_rowFrogs> memeplexer;

	if (params(argv, argc, N, s, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Frog *tmp = new Frog(process, dimension, limits);
	vector<Frog> ranas(N);
	std::for_each(ranas.begin(), ranas.end(), [=](Particle &x) { x.call_back = function_option[option]; });
	Frog::best_value_position_from_memeplexer(ranas[0]);

	for (int i = 0; i < N; i++) {
		// calculo el fitness de cada particula
		for (auto &x : ranas)
			x.fitness();
		memeplexer = Frog::meme(ranas);

		// cada memeplexer
		for (auto &x : memeplexer) {
			Frog best_particle = x[0];
			Frog worst_particle = x[0];
			best_particle.fitness();
			worst_particle.fitness();

			for (auto &j : x) {
				j.run(best_particle);
				// evaluar el fitness de cada particula
				j.fitness();

				// actualizar la mejor solucion personal de cada particula
				j.best_particle(best_particle);
				j.worst_particle(worst_particle);

				// muestro cada particula por pantalla
				j.getParameters();

				// actualizar la velocidad y posicion de cada particula
				j.limit_test();
			}
			best_particle.best_value_position(best_particle);
			worst_particle.worst_value_position(worst_particle);

			// numero de iteraciones de mejora
			for (int j = 0; j < 3; j++) {
				cout << "------------------ " << i << " ------------------\n";
				worst_particle.getParameters();
				Frog::local_search(best_particle, worst_particle);
				cout << " mejoro a la peor" << endl;
				worst_particle.getParameters();
				cout << "------------------ " << i << " ------------------\n";
			}
			bug;
			cout << " la mejor particula es \n";
			best_particle.getParameters();
			cout << " la peor particula es \n";
			worst_particle.getParameters();
			Frog::best_value_position_from_memeplexer(best_particle);
		}
		ranas = Frog::join_memeplexer();
	}

	delete tmp;
	return 0;
}
