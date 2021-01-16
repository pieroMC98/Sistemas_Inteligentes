#include "./Empleada.h"

vector<float> Empleada::neighbor(Source n) { vector<Source> xij = this->xi.getArraySolve(); }

Source Empleada::fuente_candidata(Source vi, Source random) {
	vector<Source> xk = random.getArraySolve();
	vector<float> xi = this->xi.getPosition();
	if (std::equal(xk.begin(), xk.end(), xi.begin())) return Source();

	float cmp_fitness = vi.getFitness();

	for (Source &i : this->xi.getArraySolve()) {
		float j = i.getFitness();
	}

	return vi;
}

void Empleada::run(Source &vi) {
	vi = this->fuente_candidata(vi);
	if (vi > this->xi)
		this->xi = vi;
	else
		++this->xi.limiti;
	vi = this->xi;
}
