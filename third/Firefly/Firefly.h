#include "../../second/Frog/frog.h"

class Firefly : public Frog {
	Firefly(int x, int y, int z) : Frog(x, y, z) {}
	Firefly();
	virtual void update_speed();
};
