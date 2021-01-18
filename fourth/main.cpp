#include <cstdio>

#include "../first/Function/function.h"
#include "../fourth/Bee/Bee.h"
#include "../fourth/Bee/Exploradora/Exploradora.h"
#include "../fourth/Bee/Observadora/Observadora.h"
#include "./Source/Source.h"

int main(int argc, char *argv[]) {
	int N, s, option, process, dimension, limits;

	if (params(argv, argc, N, s, option, process, dimension, limits) == EXIT_FAILURE) return EXIT_FAILURE;
	float (*function_option[])(std::vector<float>, int) = {sphere, sum_of_different_power, dixon_price};

	Particle::setStatics(process, dimension, limits);
	Source::c_b = function_option[option];
	// Source *tmp = new Source((float (*)(vector<float>, int))function_option[option]);
	vector<Source> S(N);
	vector<Bee *> abejas;
	// std::for_each(S.begin(), S.end(), [=](Particle &x) { x.call_back = function_option[option]; });
	for (Source &i : S) i.run();
	for (int i = 0; i < N; i++) abejas.push_back(new Empleada(S[i]));
	std::for_each(abejas.begin(), abejas.end(), [=](Bee *x) { x->call_back = function_option[option]; });

	vector<Observadora> observadoras(N / 5);
	vector<Exploradora> Exploradora(N);
	// std::for_each(abejas.begin(), abejas.end(), [=](Particle &x) { x.call_back = function_option[option]; });
	/* for (Source i : S) cout << "id array fuente = " << i.getID() << endl; */
	/* cout << endl; */

	/* for (Bee *i : abejas) cout << "id array abejas = " << i->getID() << endl; */
	for (int i = 0; i < N; i++) {
		size_t k;
		Source random;
		cout << "trabajo de las empleadas:\n";
		for (size_t it = 0; it < abejas.size(); it++) {
			cout << "id = " << abejas[0]->getID() << endl;
			do {
				k = rand() % abejas.size();
				random = S[k];
			} while (it == k);
			abejas[it]->run(S[it], random);
			Observadora::choose_source(S);
		}
		cout << "trabajo de las observadoras:\n";

		for (size_t it = 0; it < observadoras.size(); it++) {
			do {
				k = rand() % observadoras.size();
				random = S[k];
			} while (it == k);

			abejas.push_back(observadoras[it].run(S[it], random));
		}
	}

	// delete tmp;
	return EXIT_SUCCESS;
}
