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
	virtual void run(Source &) = 0;

	// clang-format off
	friend bool operator> <>(const Bee &, const Bee &);
	friend bool operator< <>(const Bee &, const Bee &);
	// clang-format on
	std::vector<float> getPosition();
};
