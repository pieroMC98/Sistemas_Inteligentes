#include "../first/Function/function.h"
#include "./Firefly/Firefly.h"

int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;
	float gamma, beta0;
	typedef vector<Frog> _rowFrogs;
	vector<_rowFrogs> memeplexer;

	if (third::params(argv, argc, N, s, option, process, dimension, limits, gamma, beta0) == EXIT_FAILURE)
		return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Firefly *tmp = new Firefly(process, dimension, limits);
	Firefly::gamma = gamma;
	Firefly::beta0 = beta0;
	vector<Firefly> luciernagas(N);
	Firefly thebest;
	std::for_each(luciernagas.begin(), luciernagas.end(),
		      [=](Particle &x) { x.call_back = function_option[option]; });

	for (Firefly &i : luciernagas) i.fitness();
	thebest = Firefly::sort(luciernagas);

	cout << "la mejor particula es:\n";
	thebest.getParameters();
	cout << "\n\n";
	for (int i = 0; i < N; i++) {
		for (Firefly &i : luciernagas) {
			if (i.is_thebest()) continue;
			cout << "luciernaga :\n";
			i.getParameters();
			cout << "\n\n se mueve :\n";
			for (auto j : luciernagas) {
				i.move(j);
				i.getParameters();
			}
			cout << "\n\n";
		}
		cout << "--------------------------- " << i << " ---------------------------\n";
		// cout << "\n\n\n";
		Firefly::move_best(thebest);
		cout << " la mejor se mueve: \n";
		thebest.getParameters();
	}

	delete tmp;
	return EXIT_SUCCESS;
}