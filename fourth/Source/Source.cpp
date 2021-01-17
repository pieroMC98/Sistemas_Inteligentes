#include "./Source.h"

float Source::xmin, Source::xmax;
int Source::D = {};
Source::Source() {
	Particle::counter();
	Particle::setProcess();
	srand(time(NULL) + this->getID() * MAX_POS);
	Particle::dimension();
	Particle::limit();
	this->position.resize(this->Dimension);
	std::for_each(this->position.begin(), this->position.end(),
		      [this](float &x) { x = this->random_float(-this->limits, this->limits); });
	this->solves_array.resize(Source::D);

	for (auto i : this->solves_array) this->solves_array.push_back(Source(this->random_float(0, 1)));
	this->limiti = 0;
}

Source::Source(float rand) {
	for (float &j : this->position) j = Source::xmin + rand * (Source::xmax - Source::xmin);
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
