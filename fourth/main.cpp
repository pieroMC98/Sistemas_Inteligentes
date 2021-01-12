#include "../first/Function/function.h"
#include "../fourth/Bee/Bee.h"

int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;
	typedef vector<Frog> _rowFrogs;
	vector<_rowFrogs> memeplexer;

	if (params(argv, argc, N, s, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Frog *tmp = new Firefly(process, dimension, limits);
	vector<Frog> ranas(N);
	std::for_each(ranas.begin(), ranas.end(), [=](Particle &x) { x.call_back = function_option[option]; });
	Frog::best_value_position_from_memeplexer(ranas[0]);

	delete tmp;
	return EXIT_SUCCESS;
}
