#include "./Observadora.h"
Source Observadora::prob = {};

/**
 * @brief elige por porbabilidad la mejor fuente de todas
 *
 * @param S array de fuentes a analizar
 */
void Observadora::choose_source(vector<Source> S) {
	float pj = 0;
	vector<float> pi(S.size());
	vector<Source>::iterator it = S.begin();

	for (Source i : S) pj += i.getFitness();

	for (float& j : pi) {
		j = it->getFitness() / pj;
		*it++;
	}

	it = S.begin();
	for (auto k : S)
		if (k > *it) {
			*it = k;
			*it++;
		}
	Observadora::prob = *it;
}

/**
 * @brief ejecución de la abeja observadora
 *
 * @return Bee* devuelve Empleada
 */
Bee* Observadora::run() { return new Empleada(Observadora::prob); }
