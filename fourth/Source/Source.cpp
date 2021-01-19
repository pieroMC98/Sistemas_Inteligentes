#include "./Source.h"

float Source::xmin = 1, Source::xmax = 10;
int Source::sol = 4;
Call Source::c_b = NULL;
int Source::ID = 0;

Source::Source() : Particle() {
	this->limiti = 0;
	this->call_back = Source::c_b;
};

void Source::setArraySolve() {
	std::for_each(this->position.begin(), this->position.end(),
		      [&](float &j) { j = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin); });
}

Source::Source(float i) {
	this->id = Source::ID++;
	this->limiti = 0;
	srand(time(NULL) + this->getID() * MAX_POS);
	this->call_back = Source::c_b;
	for (auto &i : this->position) i = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin);
	this->fitness();
}

void Source::setPosition(std::vector<float> x) {
	this->position = x;
	this->value = Source::c_b(this->position, this->position.size());
}

void Source::getParameters() {
	std::cout << "fuente en la posicion (";
	for (auto x : this->position) std::cout << x << " ";
	std::cout << "\b)\nfitness = " << this->getFitness() << std::endl;
}

float Source::getFitness() { return this->value; }

std::vector<Source> Source::getArraySolve() { return this->solves_array; }
void Source::setArraySolve(std::vector<Source> i) { this->solves_array = i; }
void Source::update_arraySolve() {
	for (Source &j : this->getArraySolve()) j.fitness();
}
std::vector<float> Source::getPosition() { return this->position; }

void Source::run() {
	this->fitness();
	for (int i = 0; i < Source::sol; i++) this->solves_array.push_back(Source((float)this->random_float(0, 1)));
}
