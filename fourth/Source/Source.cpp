#include "./Source.h"

#include <cstdio>
float Source::xmin = 5, Source::xmax = 10;
int Source::sol = 5;

void Source::setArraySolve() {
	std::for_each(this->position.begin(), this->position.end(), [&](float &j) {
		j = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin);
	});
	// for (auto &j : this->position) j = Source::xmin + this->random_float(0,1) * (Source::xmax - Source::xmin);
	this->fitness();
	bug;
}

Source::Source(float i) {
	std::for_each(this->position.begin(), this->position.end(), [&](float &j) {
		j = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin);
	});
	this->fitness();
}

void Source::setPosition(std::vector<float> x) {
	this->position = x;
	this->fitness();
}

void Source::getParameters() {
	std::cout << " fuenta en la posicion (";
	for (auto x : this->position) std::cout << x << " ";
	std::cout << "\b)\nfitness = " << this->getFitness() << std::endl;
}

float Source::getFitness() { return this->value; }

std::vector<Source> Source::getArraySolve() { return this->solves_array; }
void Source::setArraySolve(std::vector<Source> i) { this->solves_array = i; }
std::vector<float> Source::getPosition() { return this->position; }
