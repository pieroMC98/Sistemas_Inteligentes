#include "../../first/Particle/PSO.h"
using namespace std;
class Frog : public Particle {
       public:
	Frog() : Particle() {}
	Frog(int x, int y, int z) : Particle(x, y, z) {}
	~Frog() {}

	void sort(vector<Frog>);
	friend bool operator>(const Frog&, const Frog&);
};
