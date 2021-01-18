#include "function.h"
#include <ostream>

/**
 * @brief función esfera
 *
 * @param x arrray de posición de cada partícula
 * @param i dimensión del sistema
 * @return float solución del problema
 */
float sphere(std::vector<float> x, int i) {
	float r = 0;
	for (int j = 0; j < i; j++) r += pow(x[j], 2.0);
	return r;
}

/**
 * @brief función suma de diferencia cuadrática
 *
 * @param x arrray de posición de cada partícula
 * @param i dimensión del sistema
 * @return float solución del problema
 */
float sum_of_different_power(std::vector<float> x, int i) {
	if (!i) return pow(abs(x[i]), i + 1);
	return sum_of_different_power(x, i - 1) + pow(abs(x[i]), i + 2);
}

/**
 * @brief función dixon price
 *
 * @param x arrray de posición de cada partícula
 * @param i dimensión del sistema
 * @return float solución del problema
 */
float dixon_price(std::vector<float> x, int i) {
	if (i > 0) return dixon_price(x, i - 1) + (i + 1) * pow(2 * pow(x[i], 2) - x[i - 1], 2);
	return pow((x[i] - 0), 2);
}

/**
 * @brief selección de la función a trabajar
 *
 * @return int elección del usuario
 */
int select_function() {
	std::string option;
	std::cout << "Elija la funcion fitness: sphere(0) | sum_of_different_power(1) | dixon_price(2)" << std::endl;
	std::getline(std::cin, option);
	return atoi(option.c_str());
}

/**
 * @brief parametros que recibe el programa
 *
 * @return int si se han recibido los parametros
 */
int params(char **argv, int argc, int &N, int &s, int &option, int &process, int &dimension, int &limits) {
	if (argc == 7) {
		N = atoi(argv[1]);
		s = atoi(argv[2]);
		option = atoi(argv[3]);
		process = atoi(argv[4]);
		dimension = atoi(argv[5]);
		limits = atoi(argv[6]);
		return EXIT_SUCCESS;
	} else {
		std::cout << "los parámetros son:\n\
			1º - número de partículas\n\
			2º - número de iteraciones\n\
			3º - funcion para el fitness: sphere(0) | sum_of_different_power(1) | dixon_price(2)\n\
			4º - proceso de optimizado: 1> minimizar, 2> maximizar\n\
			5º - dimension del sistema\n\
			6º - limite del sistema\n";
		return EXIT_FAILURE;
	}
}

/**
 * @brief
 *
 * @param v1
 * @param v2
 * @return vector<float>
 */
std::vector<float> operator+(const std::vector<float> &v1, const std::vector<float> &v2) {
	if (v1.size() != v2.size()) return std::vector<float>();

	std::vector<float> aux(v1.size());
	for (size_t i = 0; i < v1.size(); i++) aux[i] = v1[i] + v2[i];
	return aux;
}

/**
 * @brief parametros que recibe el programa
 *
 * @return int si se han recibido los parametros
 */
int third::params(char **argv, int argc, int &N, int &s, int &option, int &process, int &dimension, int &limits,
		  float &gamma, float &beta0) {
	if (argc == 9) {
		N = atoi(argv[1]);
		s = atoi(argv[2]);
		option = atoi(argv[3]);
		process = atoi(argv[4]);
		dimension = atoi(argv[5]);
		limits = atoi(argv[6]);
		gamma = atof(argv[7]);
		beta0 = atof(argv[8]);
		return EXIT_SUCCESS;
	}

	std::cout << "los parámetros son:\n\
		1º - número de partículas\n\
		2º - número de iteraciones\n\
		3º - funcion para el fitness: sphere(0) | sum_of_different_power(1) | dixon_price(2)\n\
		4º - proceso de optimizado: 1> minimizar, 2> maximizar\n\
		5º - dimension del sistema\n\
		6º - limite del sistema\n\
		7º - gamma del sistema\n\
		8º - beta0 del sistema\n";
	return EXIT_FAILURE;
}
