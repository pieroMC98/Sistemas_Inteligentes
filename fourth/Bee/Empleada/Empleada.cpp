#include "./Empleada.h"

Source Empleada::fuente_candidata(Source vi) {
	vector<float> xk = vi.getPosition();
	vector<float> xi = this->xi.getPosition();
	if (std::equal(xk.begin(), xk.end(), xi.begin())) return Source();

	vector<float> alfa = xi - xk;
	for (float &x : alfa) x *= this->random_float(-1, 1);

	vi.setPosition(xi + alfa);
	return vi;
}

void Empleada::run(Source &vi) {
	vi = this->fuente_candidata(vi);
	if (vi > this->xi)
		this->xi = vi;
	else
		++this->xi.limiti;
	vi = this->xi;
}
