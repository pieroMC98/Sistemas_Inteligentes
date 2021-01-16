#include "../../Operator/operator.h"
#include "../../Template/template.h"
#include "../../second/Frog/frog.h"
class Firefly : public Frog {
	bool best = false;

       public:
	static float gamma, beta0;
	static Firefly sort(vector<Firefly> &);
	void move_best();
	float getFitness();
	Firefly(int x, int y, int z) : Frog(x, y, z) {}

	Firefly() : Frog() {}
	~Firefly(){}
	void update_position(Firefly);
	void move(Firefly);
	float betai(Firefly);
	bool is_thebest();
	// clang-format off
	friend bool operator> <>(const Firefly &, const Firefly &);
	friend bool operator< <>(const Firefly &, const Firefly &);
	// clang-format on
};
