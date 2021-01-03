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
	Frog best_particle = ranas[0];
	Frog worst_particle = ranas[0];
	best_particle.fitness();
	worst_particle.fitness();

	for (int i = 0; i < N; i++) {
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
			// x.update_speed(0.729, 2.05, 2.05);
			x.update_position();
			x.limit_test();
		}
		memeplexer = Frog::meme(ranas);

		for (auto &x : memeplexer) {
			Frog::best_value_position_from_memeplexer(best_particle);
			best_particle = x[0];
			for (int j = 0; j < 3; j++) {
				for (auto &j : x) {
					j.run(best_particle);
					// evaluar el fitness de cada particula
					j.fitness();

					// actualizar la mejor solucion personal de cada particula
					j.Set_best_personal_properties();
					j.best_particle(best_particle);
					j.worst_particle(worst_particle);

					// muestro cada particula por pantalla
					j.getParameters();
					best_particle.best_value_position(best_particle);
					worst_particle.worst_value_position(worst_particle);
					// j.update_speed(0.729, 2.05, 2.05);
					j.update_position();

					// actualizar la velocidad y posicion de cada particula
					j.limit_test();
				}
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
			best_particle.getGlobalParameters();
		}
		ranas = Frog::join_memeplexer();
	}
	// for_each(ranas.begin(), ranas.end(), [=](Frog x) { x.getParameters(); });

	tmp->~Frog();
	return 0;
}
