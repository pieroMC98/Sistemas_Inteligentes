#include "./Empleada.h"
/**
 * @brief Abeja elige una fuente candidata
 *
 * @param random fuente aleatoria a procesas
 * @return Source devuelve la mejor fuente encontrada
 */
Source Empleada::fuente_candidata(Source random) {
	Source vi = this->xi;
	vector<Source> xk = random.getArraySolve();
	vector<Source>::iterator j = xk.begin();
	vector<float> alfa(this->Dimension);

	std::fill(alfa.begin(), alfa.end(), this->random_float(-1, 1));

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
	for (Source it : vi.getArraySolve()) {
		if (this->process == MAXIMIZAR) {
			if (it > max) max = it;
		} else if (it < max)
			max = it;
	}
	vi = max;
	vi.setArraySolve(vij);
	return vi;
}

/**
 * @brief ejecución de la abeja empleada
 *
 * @param vi fuente actual en uso
 * @param random fuente aleatiora para elegir candidada
 * @return Bee* devuelve Exploradora si la actual fuente no se puede optimizar más
 */
Bee *Empleada::run(Source &vi, Source random) {
	this->fitness();
	Source aux = this->fuente_candidata(random);
	this->getParameters();
	if (this->process == MAXIMIZAR) {
		if (aux > this->xi) {
			this->xi = aux;
			cout << "\033[1;35mEncontrada mejor fuente vecina\033[0m\n";
			this->xi.getParameters();
			vi = this->xi;
		} else
			++this->xi.limiti;
	} else {
		if (aux < this->xi) {
			this->xi = aux;
			cout << "\033[1;35mEncontrada mejor fuente vecina\033[0m\n";
			this->xi.getParameters();
			vi = this->xi;
		} else
			++this->xi.limiti;
	}
	if (xi.limiti == 5) return new Exploradora();
	return NULL;
}

/**
 * @brief imprimir parámetros
 *
 */
void Empleada::getParameters() {
	std::cout << "\033[1;31m--------------------------------------\033[0m";
	std::cout << "\n\033[1;35mAbeja " << this->getID() << "\033[0m\n";
	std::cout << "value = " << this->value << "\n";
	std::cout << "position(Fuente): | \n";
	this->xi.getParameters();
}
