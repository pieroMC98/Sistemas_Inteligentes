#include "./Firefly/Firefly.h"
#include "../first/Function/function.h"
int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;
	typedef vector<Frog> _rowFrogs;
	vector<_rowFrogs> memeplexer;

	if (params(argv, argc, N, s, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Firefly *tmp = new Firefly(process, dimension, limits);
	vector<Firefly> luciernagas(N);
	std::for_each(luciernagas.begin(), luciernagas.end(), [=](Particle &x) { x.call_back = function_option[option]; });


	for( int i = 0; i < N; i++ ) {
		for( Firefly &i : luciernagas  ) i.fitness();
	}

	return EXIT_SUCCESS;
}
