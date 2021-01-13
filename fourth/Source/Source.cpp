#include "./Source.h"

void Source::getParameters() {
	std::cout << " fuenta en la posicion (";
	for (auto x : this->position) std::cout << x << " ";
	std::cout << "\b)\nfitness = " << this->getFitness() << std::endl;
}

float Source::getFitness() { return this->value; }
