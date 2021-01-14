#include "./Firefly.h"

#include "../../Template/template.h"

float Firefly::gamma = {};
float Firefly::beta0 = {};

float Firefly::betai(Firefly neighbor) {
	vector<float> rij = this->position - neighbor.position;
	float modulo = this->module_vector(rij, rij.size());
	return pow(Firefly::beta0, -gamma * pow(modulo, 2.0));
}

Firefly Firefly::sort(vector<Firefly> &l) {
	for (size_t i = 0; i < l.size(); i++)
		for (size_t j = 0; j < l.size() - 1; j++)
			if (l[j] > l[j + 1]) {
				Firefly aux = l[j];
				l[j] = l[j + 1];
				l[j + 1] = aux;
			}

	for (auto s : l) s.getParameters();
	if (l[0].process == MINIMIZAR) {
		l.front().best = true;
		return l.front();
		getchar();
	}

	l.back().best = true;
	return l.back();
}

void Firefly::update_position(Firefly neighbor) {
	std::vector<float> beta(neighbor.Dimension), diff(neighbor.Dimension);
	vector<float> epsilon(neighbor.Dimension);

	std::for_each(epsilon.begin(), epsilon.end(),
		      [this](float &x) { x = this->random_float(-this->limits / 5, this->limits / 5); });

	diff = neighbor.position - this->position;
	std::for_each(beta.begin(), beta.end(), [&](float &v) { v = betai(neighbor); });
	this->position = this->position + (beta * diff) + epsilon;
}

void Firefly::move(Firefly x) {
	if (this->process == MAXIMIZAR) {
		if (x > *this && this->best == false) {
			this->update_position(x);
			this->fitness();
		}
	} else if (x < *this && this->best == false) {
		this->update_position(x);
		this->fitness();
	}
}

void Firefly::move_best() {
	std::for_each(this->position.begin(), this->position.end(),
		      [this](float &x) { x = this->random_float(-this->limits, this->limits); });
	this->limit_test();
}

bool Firefly::is_thebest() { return this->best; }

float Firefly::getFitness() { return this->value; }
