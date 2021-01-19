#include "./Bee.h"
int Bee::ID = 1;
Call Bee::c_b = NULL;
Bee::Bee() { this->call_back = Source::c_b; }

std::vector<float> Bee::getPosition() { return this->position; }
