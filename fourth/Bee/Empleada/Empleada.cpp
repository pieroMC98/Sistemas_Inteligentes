#include "./Empleada.h"

Source Empleada::fuente_candidata(Source vi, Source random) {
	vector<Source> xk = random.getArraySolve();
	vector<Source>::iterator j = xk.begin();
	vector<float> alfa(this->Dimension);

	std::fill(alfa.begin(), alfa.end(), this->random_float(0, 1));

	vector<Source> vij = this->xi.getArraySolve();
	vector<float> add, diff, prod;
	for_each(vij.begin(), vij.end(), [&](Source &vij) {
		diff = vij.getPosition() - j->getPosition();
		prod = alfa * diff;
		add = vij.getPosition() + prod;
		vij.setPosition(add);
		*j++;
	});
	cout << " sig inter\n\n";

	Source max = vij[0];
	for (Source it : vij) {
		if (it > max) max = it;
	}

	this->xi.setArraySolve(vij);
	return max;
}

Bee *Empleada::run(Source &vi, Source random) {
	this->fitness();
	// Source aux;
	Source aux = this->fuente_candidata(vi, random);
	this->getParameters();
	if (aux > this->xi) {
		this->xi = aux;
		cout << "\033[1;35mEncontrada mejor fuente vecina\033[0m\n";
		this->xi.getParameters();
		vi = this->xi;
	} else
		++this->xi.limiti;
	Bee *rt = new Exploradora();
	return rt;
}

void Empleada::getParameters() {
	std::cout << "\033[1;31m--------------------------------------\033[0m";
	std::cout << "\n\033[1;35mAbeja " << this->getID() << "\033[0m\n";
	std::cout << "personal value = " << this->value << "\n";
	std::cout << "position(Fuente): | \n";
	this->xi.getParameters();
	std::cout << "\b\b|\n";
}
