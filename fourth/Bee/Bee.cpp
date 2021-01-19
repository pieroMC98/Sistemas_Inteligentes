#include "./Bee.h"
/**
 * @brief inicialización variables estáticas
 *
 */
int Bee::ID = 1;
Call Bee::c_b = NULL;
/**
 * @brief Construct a new Bee:: Bee object
 *
 */
Bee::Bee() { this->call_back = Source::c_b; }

/**
 * @brief obtener posición de la abeja
 *
 * @return std::vector<float>
 */
std::vector<float> Bee::getPosition() { return this->position; }
