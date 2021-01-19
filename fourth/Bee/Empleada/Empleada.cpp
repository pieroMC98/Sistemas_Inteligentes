#include "./Empleada.h"

Source Empleada::fuente_candidata(Source random) {
	Source vi = this->xi;
	vector<Source> xk = random.getArraySolve();
	vector<Source>::iterator j = xk.begin();
	vector<float> alfa(this->Dimension);

	std::fill(alfa.begin(), alfa.end(), this->random_float(0, 1));

	vector<Source> vij = vi.getArraySolve();
	vector<float> add, diff, prod;
	for_each(vij.begin(), vij.end(), [&](Source &vij) {
		diff = vij.getPosition() - j->getPosition();
		prod = alfa * diff;
		add = vij.getPosition() + prod;
		vij.setPosition(add);
		*j++;
	});
	vi.setArraySolve(vij);


	Source max = this->xi;
	for (Source it : vi.getArraySolve())
		if (it > max) max = it;
	vi = max;
	vi.setArraySolve(vij);
	return vi;
}

Bee *Empleada::run(Source &vi, Source random) {
	this->fitness();
	Source aux = this->fuente_candidata(random);
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
	std::cout << "value = " << this->value << "\n";
	std::cout << "position(Fuente): | \n";
	this->xi.getParameters();
	std::cout << "\b\b|\n";
}
