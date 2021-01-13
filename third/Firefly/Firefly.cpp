#include "./Firefly.h"

#include "../../Template/template.h"

float Firefly::gamma = {};
float Firefly::beta0 = {};

float Firefly::betai(Firefly neighbor) {
	vector<float> rij = this->position - neighbor.position;
	return pow(Firefly::beta0,
		   -gamma * this->module_vector(rij, rij.size()) * this->module_vector(rij, rij.size()));
}

Firefly Firefly::sort(vector<Firefly> &l) {
	for (size_t i = 1; i < l.size(); i++)
		if (l[i - 1] > l[i]) {
			Firefly aux = l[i];
			l[i] = l[i - 1];
			l[i - 1] = aux;
		}
	l.back().best = true;
	return l.back();
}

void Firefly::update_position(Firefly neighbor) {
	std::vector<float> beta(neighbor.Dimension), diff(neighbor.Dimension);
	vector<float> epsilon(neighbor.Dimension);

	std::generate(epsilon.begin(), epsilon.end(), std::rand);

	diff = this->position - neighbor.position;
	std::for_each(beta.begin(), beta.end(),
		      [&](float &v) { v = v * betai(neighbor) * this->random_float(0.1, 1.0); });
	this->position = this->position + beta * diff + epsilon;
}

void Firefly::move(Firefly x) {
	if (x > *this && this->best == false) update_position(x);
}

void Firefly::move_best(Firefly &best) {
	vector<float> rand(best.Dimension);
	std::generate(rand.begin(), rand.end(), std::rand);
	best.position = best.position + rand;
}

bool Firefly::is_thebest() { return this->best; }
