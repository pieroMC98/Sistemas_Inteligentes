#include "../../first/Particle/PSO.h"
using namespace std;
class Frog : public Particle {
       private:
	int meme_id;

       public:
	Frog() : Particle() {}
	Frog(int x, int y, int z) : Particle(x, y, z) {}
	~Frog() {}

	void sort(vector<Frog>&);
	void memeplexer(vector<Frog>&);
	friend bool operator>(const Frog&, const Frog&);
	virtual void getParameters();
};
