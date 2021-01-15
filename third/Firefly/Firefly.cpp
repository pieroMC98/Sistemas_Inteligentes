#include "./Firefly.h"

#include "../../Template/template.h"

/**
 * @brief  inicio de variables estáticas
 *
 */
float Firefly::gamma = {};
float Firefly::beta0 = {};

/**
 * @brief valor de beta
 *
 * @param neighbor vecino próximo
 * @return float devuelve el valor beta
 */
float Firefly::betai(Firefly neighbor) {
	vector<float> rij = this->position - neighbor.position;
	float modulo = this->module_vector(rij, rij.size());
	return pow(Firefly::beta0, -gamma * pow(modulo, 2.0));
}

/**
 * @brief ordena el array de luciernagas
 *
 * @param l recibe el array de luciernagas por referencia
 * @return Firefly devuelve la mejor luciernaga
 */
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

/**
 * @brief actualiza la posición de la luciernaga respecto a su vecino
 *
 * @param neighbor vecino próximo
 */
void Firefly::update_position(Firefly neighbor) {
	std::vector<float> beta(neighbor.Dimension), diff(neighbor.Dimension);
	vector<float> epsilon(neighbor.Dimension);

	std::for_each(epsilon.begin(), epsilon.end(),
		      [this](float &x) { x = this->random_float(-this->limits / 5, this->limits / 5); });

	diff = neighbor.position - this->position;
	std::for_each(beta.begin(), beta.end(), [&](float &v) { v = betai(neighbor); });
	this->position = this->position + (beta * diff) + epsilon;
}

/**
 * @brief mueve la luciernaga dependiendo de la optimización del sistema
 *
 * @param neighbor vecino de la luciernaga
 */
void Firefly::move(Firefly neighbor) {
	if (this->process == MAXIMIZAR) {
		if (neighbor > *this && this->best == false) this->update_position(neighbor);
	} else if (neighbor < *this && this->best == false)
		this->update_position(neighbor);
	this->fitness();
}

/**
 * @brief mueve a la mejor lucernaga aleatoriamente
 *
 */
void Firefly::move_best() {
	std::for_each(this->position.begin(), this->position.end(),
		      [this](float &x) { x = this->random_float(-this->limits, this->limits); });
	this->limit_test();
}

/**
 * @brief devuelve si la particula es la mejor
 *
 * @return true
 * @return false
 */
bool Firefly::is_thebest() { return this->best; }

/**
 * @brief devuelve el fitness de la luciernaga
 *
 * @return float
 */
float Firefly::getFitness() { return this->value; }
