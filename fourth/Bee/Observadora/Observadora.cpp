#include "./Observadora.h"

Source Observadora::prob = {};
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

Bee* Observadora::run(Source& vi, Source random) {
	vi = Observadora::prob;
	Bee* rt = new Empleada(vi);
	rt->run(vi, random);
	return rt;
}
