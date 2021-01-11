#include "function.h"

/**
 * @brief función esfera
 *
 * @param x arrray de posición de cada partícula
 * @param i dimensión del sistema
 * @return float solución del problema
 */
float sphere(std::vector<float> x, int i) {
  float r = 0;
  for (int j = 0; j < i; j++)
    r += pow(x[j], 2);
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
  if (!i)
    return pow(abs(x[i]), i + 1);
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
  if (i > 0)
    return dixon_price(x, i - 1) +
           (i + 1) * pow(2 * pow(x[i], 2) - x[i - 1], 2);
  return pow((x[i] - 0), 2);
}

/**
 * @brief selección de la función a trabajar
 *
 * @return int elección del usuario
 */
int select_function() {
  std::string option;
  std::cout << "Elija la funcion fitness: sphere(0) | "
               "sum_of_different_power(1) | dixon_price(2)"
            << std::endl;
  std::getline(std::cin, option);
  return atoi(option.c_str());
}

namespace trird {

/**
 * @brief parametros que recibe el programa
 *
 * @return int si se han recibido los parametros
 */
int params(char **argv, int argc, int &N, int &s, int &option, int &process,
           int &dimension, int &limits) {
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
} // namespace trird
