#ifndef _PSO_H
#define _PSO_H
#include <math.h>
#include <stdlib.h>

#include "Template/template.h"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#define MAX_POS 1000
#define MINIMIZAR 1
#define MAXIMIZAR 2
#define EXIT 10

#define bug std::cout << "-------8888--------" << std::endl
std::vector<float> operator+(const std::vector<float> &,
                             const std::vector<float> &);
#endif
