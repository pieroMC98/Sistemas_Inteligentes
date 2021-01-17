#ifndef _BEE_BASE
#define _BEE_BASE
#include "../../Operator/operator.h"
#include "../../Template/template.h"
#include "../Source/Source.h"
#include "./../../third/Firefly/Firefly.h"

class Bee : public Firefly {
       public:
	Source xi;
	Bee(int x, int y, int z) : Firefly(x, y, z) {}
	Bee() : Firefly() {}
	virtual ~Bee(){};
	virtual Bee* run(Source &,Source){ return new Bee(); }

	// clang-format off
	friend bool operator> <>(const Bee &, const Bee &);
	friend bool operator< <>(const Bee &, const Bee &);
	// clang-format on
	std::vector<float> getPosition();
};
#endif
