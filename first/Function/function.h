#include "../../HEADER_H.h"

float sphere(std::vector<float>, int);
float sum_of_different_power(std::vector<float>, int);
float dixon_price(std::vector<float>, int);
int select_function();
int params(char **, int, int &, int &, int &, int &, int &, int &);
namespace third {
int params(char **argv, int argc, int &N, int &s, int &option, int &process, int &dimension, int &limits, float &gamma,
	   float &beta0);
}
