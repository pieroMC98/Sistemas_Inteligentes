#include "./Source.h"

float Source::xmin = 5, Source::xmax = 10;
int Source::sol = 4;
Call Source::c_b = NULL;

//Source::Source(float (*call)(std::vector<float>, int)) { this->setCall(call); }

Source::Source() : Particle() { this->call_back = Source::c_b; };

void Source::setArraySolve() {
	std::for_each(this->position.begin(), this->position.end(),
		      [&](float &j) { j = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin); });
}

Source::Source(float i) {
	srand(time(NULL) + this->getID() * MAX_POS);
	this->call_back = Source::c_b;
	for (auto &i : this->position)
		i = Source::xmin + this->random_float(0, 1) * (Source::xmax - Source::xmin);
	this->fitness();
}

void Source::setPosition(std::vector<float> x) {
	this->position = x;
	this->value = Source::c_b(this->position,this->position.size());
	std::cout<<"fit con ftiness "<<this->value<<std::endl;
	std::cout<<"fit con ftiness "<<this->getFitness()<<std::endl;
	getchar();
	bug;
}

void Source::getParameters() {
	std::cout << "fuenta en la posicion (";
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
	//	this->getParameters();
	// bug;
	// this->solves_array[0].getParameters();
}
