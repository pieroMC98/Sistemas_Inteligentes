#include "./Empleada.h"
Source Empleada::fuente_candidata(Source vi, Source random) {
	vector<Source> xk = random.getArraySolve();

	vector<Source>::iterator j = xk.begin();

	vector<float> alfa(Source::sol);
	std::fill(alfa.begin(), alfa.end(), this->random_float(0, 1));

	vector<Source> vij = this->xi.getArraySolve();
	for_each(vij.begin(), vij.end(), [&](Source &vij) {
		auto yy = vij.getPosition() + alfa * (vij.getPosition() - j->getPosition());
		bug;
		for( auto k : vij.getPosition() )
			std::cout<<" "<<k;
		bug;
		for( auto k : alfa * (vij.getPosition() - j->getPosition()) )
			std::cout<<" "<<k;
		bug;
		for( auto k : yy )
			std::cout<<" "<<k;
		bug;
		getchar();
		vij.setPosition(vij.getPosition() + alfa * (vij.getPosition() - j->getPosition()));
		*j++;
	});

	vij[0].getParameters();
	bug;
	Source max = vij[0];
	for (Source it : vij) {
		if (it > max) max = it;
	}

	this->xi.setArraySolve(vij);
	return max;
}

Bee *Empleada::run(Source &vi, Source random) {
	this->fitness();
	vi = this->fuente_candidata(vi, random);
	this->getParameters();
	if (vi > this->xi) {
		this->xi = vi;
		cout << "Encontrada mejor fuente vecina\n";
		this->xi.getParameters();
	} else
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
	std::cout << "\b|\n";
}
