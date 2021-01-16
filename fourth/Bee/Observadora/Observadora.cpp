#include "./Observadora.h"

float Observadora::sumatorio = {};

void Observadora::sum_S(vector<Source> S) {
	for (Source i : S) Observadora::sumatorio += i.getFitness();
}

Source Observadora::choose_source(Source S) {
	float pi;
	pi = S.getFitness() / Observadora::sumatorio;
}

void Observadora::run(Source vi) {}
