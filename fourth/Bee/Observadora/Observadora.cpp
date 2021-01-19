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

Bee* Observadora::run(Source vi, Source random) {
	vi = Observadora::prob;
	vi.getParameters();
	for( auto i : vi.getArraySolve() )
		i.getParameters();
	return new Empleada(vi);
}
