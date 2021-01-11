#include "./Firefly.h"
#include "../../Template/template.h"
//#include "../../Template/template.cpp"
//extern template bool operator> <Firefly>(const Firefly &r1, const Firefly &r2);
float Firefly::gamma = {};
float Firefly::beta0 = {};


float Firefly::betai(std::vector<float> neighbor) {
	vector<float> rij = this->position - neighbor;
	return pow(Firefly::beta0,-gamma*this->module_vector(rij,rij.size()));
}

void Firefly::sort(vector<Firefly> &l) {
	for (size_t i = 1; i < l.size(); i++)
		if (l[i - 1] > l[i]) {
			Firefly aux = l[i];
			l[i] = l[i - 1];
			l[i - 1] = aux;
		}
}

void Firefly::update_position(std::vector<float> neighbor) {
	int i = 0;
	std::vector<float> aux;
	std::for_each(aux.begin(),aux.end(), [&](float &v) {
			v = v*betai(neighbor)* this->random_float(0.1,1.0);
	});
	this->position = this->position + aux;
}
