#include "./Bee.h"
int Bee::ID = 1;
Bee::Bee() { this->id = Bee::ID++; }
std::vector<float> Bee::getPosition() { return this->position; }
