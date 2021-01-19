#ifndef _BEE_BASE
#define _BEE_BASE
#include "../../Operator/operator.h"
#include "../../Template/template.h"
#include "../Source/Source.h"
using namespace std;
class Bee : public Particle {
       public:
	Source xi;
	static Call c_b;
	static int ID;
	Bee();
	virtual ~Bee(){};
	virtual Bee *run(Source &, Source) { return new Bee(); }

	// clang-format off
	friend bool operator> <>(const Bee &, const Bee &);
	friend bool operator< <>(const Bee &, const Bee &);
	// clang-format on
	std::vector<float> getPosition();
};
#endif
