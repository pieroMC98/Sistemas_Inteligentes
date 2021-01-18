#include "./Empleada.h"

Source Empleada::fuente_candidata(Source vi, Source random) {
	vector<Source> xk = random.getArraySolve();

	vector<Source>::iterator j = xk.begin();

	vector<float> alfa(Source::sol);
	std::fill(alfa.begin(), alfa.end(), this->random_float(0, 1));

	vector<Source> vij = this->xi.getArraySolve();

	for_each(vij.begin(), vij.end(), [&](Source &vij) {
		vij.setPosition(vij.getPosition() + alfa * (vij.getPosition() - j->getPosition()));
		*j++;
	});

	Source max = vij[0];
	for (Source it : vij) {
		if (it > max) max = it;
	}

	this->xi.setArraySolve(vij);
	return max;
}

Bee *Empleada::run(Source &vi, Source random) {
	this->fitness();
	vi = this->fuente_candidata(vi, Source());
	this->getParameters();
	if (vi > this->xi)
		this->xi = vi;
	else
		++this->xi.limiti;
	vi = this->xi;
	Bee *rt = new Exploradora();
	return rt;
}

void Empleada::getParameters() {
	std::cout << "\033[1;31m--------------------------------------\033[0m";
	std::cout << "\n\033[1;35mAbeja " << this->getID() << "\033[0m\n";
	std::cout << " personal value = " << this->value << "\n";
	std::cout << "position(Fuente): | \n";
	this->xi.getParameters();
	std::cout << "\b\n|\n";
}
