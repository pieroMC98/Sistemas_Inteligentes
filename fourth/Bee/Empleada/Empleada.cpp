#include "./Empleada.h"

Source Empleada::fuente_candidata(Source vi, Source random) {
	vector<Source> xk = random.getArraySolve();

	vector<Source>::iterator j = xk.begin();
	
	vector<float> alfa(Source::D);
	std::fill(alfa.begin(), alfa.end(), this->random_float(0, 1));

	vector<Source> vij = this->xi.getArraySolve();

	for_each(vij.begin(),vij.end(), [&](Source &vij){
		vij.setPosition(vij.getPosition() + alfa*(vij.getPosition() - j->getPosition()));
		*j++;
			});

	Source max = vij[0];
	for(Source it : vij) {
		if( it > max )
			max = it;
	}

	this->xi.setArraySolve(vij);
	return max;
}

void Empleada::run(Source &vi, Source random) {
	vi = this->fuente_candidata(vi,Source());
	if (vi > this->xi)
		this->xi = vi;
	else
		++this->xi.limiti;
	vi = this->xi;
}
