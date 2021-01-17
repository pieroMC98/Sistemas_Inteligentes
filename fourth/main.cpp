#include "../first/Function/function.h"
#include "../fourth/Bee/Bee.h"
//#include "../fourth/Bee/Empleada/Empleada.h"
#include "../fourth/Bee/Exploradora/Exploradora.h"
#include "../fourth/Bee/Observadora/Observadora.h"

int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;
	typedef vector<Frog> _rowFrogs;
	vector<_rowFrogs> memeplexer;

	if (params(argv, argc, N, s, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Source *tmp = new Source(process, dimension, limits);
	vector<Source> S(N);
	vector<Empleada> abejas(N);
	vector<Observadora> observadoras(N);
	vector<Exploradora> Exploradora(N);
	std::for_each(abejas.begin(), abejas.end(), [=](Particle &x) { x.call_back = function_option[option]; });

	for (int i = 0; i < N; i++) {
		for (size_t it = 0; it < abejas.size(); it++) {
			int k;
			Source random;
			do {
				k = rand() % abejas.size();
				random = S[k];
			} while (it == k);

			abejas[it].run(S[it], random);
			observadoras[it].run(S[it], random);
		}
	}

	delete tmp;
	return EXIT_SUCCESS;
}
