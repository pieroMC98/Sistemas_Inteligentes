#include "../first/Function/function.h"
#include "../second/Frog/frog.h"

int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;
	typedef vector<Frog> _rowFrogs;
	vector<_rowFrogs> memeplexer;

	if (params(argv, argc, N, s, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	//Frog *tmp = new Frog(process, dimension, limits);
	Particle::setStatics(process,dimension,limits);
	vector<Frog> ranas(N);
	std::for_each(ranas.begin(), ranas.end(), [=](Particle &x) { x.call_back = function_option[option]; });

	for (int i = 0; i < N; i++) {
		// calculo el fitness de cada particula
		for (auto &x : ranas) x.fitness();
		memeplexer = Frog::meme(ranas);
		Frog::best_value_position_from_memeplexer(process == MAXIMIZAR ? ranas.back() : ranas.front());

		// cada memeplexer
		for (auto &x : memeplexer) {
			cout << "memeplexer_id : \n";
			cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>> " << x[0].getMeme_id() << " <<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
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
			cout << "\033[1;33m\n>MEJORANDO LA PEOR PARTICULA< \033[0m" << worst_particle.getID() << endl;
			for (int j = 0; j < 3; j++) {
				Frog::local_search(best_particle, worst_particle);
				replace_if(
					x.begin(), x.end(),
					[&](Frog k) -> bool { return k.getID() == worst_particle.getID(); },
					worst_particle);
				worst_particle.getParameters();
			}
			if ((worst_particle < best_particle && process == MINIMIZAR) ||
			    (worst_particle > best_particle && process == MAXIMIZAR))
				best_particle = worst_particle;

			cout << "\033[1;33m>MEJORA TERMINADA \033[0m" << endl << endl;
			cout << "la mejor particula es \n";
			best_particle.getParameters();
			Frog::best_value_position_from_memeplexer(best_particle);
		}
		cout << "--------------------------- " << i << " ---------------------------\n";
		ranas = Frog::join_memeplexer(memeplexer);
	}
	cout << "\n\nla mejor solucion es \n";
	Frog::global_best.back().getParameters();
	//delete tmp;
	return EXIT_SUCCESS;
}
