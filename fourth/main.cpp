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
	Bee::c_b = function_option[option];

	vector<Source> S(N);
	vector<Bee *> abejas;
	for (Source &i : S) i.run();
	for (int i = 0; i < N; i++) abejas.push_back(new Empleada(S[i]));

	vector<Observadora> observadoras(5);
	for (int i = 0; i < s; i++) {
		size_t k;
		Source random;
		cout << "\ntrabajo de las empleadas(" << abejas.size() << ")\n";
		for (size_t it = 0; it < S.size(); it++) {
			do {
				k = rand() % S.size();
			} while (it == k);
			random = S.at(k);
			Bee *ex = abejas[it]->run(S[it], random);
			if (ex != nullptr) {
				cout << "trabajo de las Exploradoras\n";
				Source *aux = new Source();
				ex = new Empleada(*aux);
				S.push_back(*aux);
				cout << "encuentran nueva fuente\n";
				aux->fitness();
				aux->getParameters();
			}
		}

		cout << "\ntrabajo de las observadoras:\n";
		Observadora::choose_source(S);
		for (size_t it = 0; it < observadoras.size(); it++) {
			Bee *ty = observadoras[it].run();
			abejas.push_back(ty);
		}
		cout << "van hacia:\n";
		Observadora::prob.getParameters();
		std::cout << "\n\033[1;32m################### " << i << " #############################\033[0m";
	}

	cout << "\nmejor solucion del sistema:\n";
	Observadora::prob.getParameters();

	// delete tmp;
	return EXIT_SUCCESS;
}
