#include "../../Operator/operator.h"
#include "../../Template/template.h"
#include "./../../third/Firefly/Firefly.h"
#include "../Source/Source.h"
class Bee : public Firefly {
       public:
	Bee(int x, int y, int z) : Firefly(x, y, z) {}
	Bee() : Firefly() {}
	virtual ~Bee(){};
	Source src;
};
