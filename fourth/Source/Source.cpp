#include "./Source.h"

float Source::xmin, Source::xmax;
Source::Source() {
	Particle::counter();
	Particle::setProcess();
	srand(time(NULL) + this->getID() * MAX_POS);
	Particle::dimension();
	Particle::limit();
	this->position.resize(this->Dimension);
	std::for_each(this->position.begin(), this->position.end(),
		      [this](float &x) { x = this->random_float(-this->limits, this->limits); });
	this->gen_solves_array();
	this->limiti = 0;
}

void Source::gen_solves_array() {
	for (float &j : this->solves_array) j = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin);
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

std::vector<float> Source::getArraySolve() { return this->solves_array; }
