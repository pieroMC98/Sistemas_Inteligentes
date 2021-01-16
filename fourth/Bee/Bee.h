#include "../../Operator/operator.h"
#include "../../Template/template.h"
#include "../Source/Source.h"
#include "./../../third/Firefly/Firefly.h"
class Bee : public Firefly {
       public:
	Bee(int x, int y, int z) : Firefly(x, y, z) {}
	Bee() : Firefly() {}
	virtual ~Bee(){};
	virtual void run(Source);
	Source xi;
};
