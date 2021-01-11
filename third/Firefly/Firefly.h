#include "../../Operator/operator.h"
#include "../../Template/template.h"
#include "../../second/Frog/frog.h"
class Firefly : public Frog {
	bool best = false;

       public:
	static float gamma, beta0;
	static Firefly sort(vector<Firefly> &);
	static void move_best(Firefly &);
	Firefly(int x, int y, int z) : Frog(x, y, z) {}

	Firefly() : Frog() {}
	virtual ~Firefly(){};
	void update_position(Firefly);
	void move(Firefly);
	float betai(Firefly);
	// clang-format off
	friend bool operator> <>(const Firefly &, const Firefly &);
	friend bool operator< <>(const Firefly &, const Firefly &);
	// clang-format on
};
