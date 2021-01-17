#include "./Observadora.h"

float Observadora::choose_source(Source S) {
	float pj = 0;
	for (Source j : S.getArraySolve()) pj += j.getFitness();
	return S.getFitness() / pj;
}

void Observadora::run(Source &vi, Source random) {
	float Probi = choose_source(vi);
	Empleada rt;
	rt.run(vi, random);
}
