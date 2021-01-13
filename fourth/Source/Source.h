#include "../../first/Particle/PSO.h"

class Source : private Particle {
       public:
	Source() : Particle() {}
	Source(int p, int d, int l) : Particle(p, d, l) {}
	virtual ~Source() {}
	std::vector<float> getPosition();
	void getParameters() override;
	float getFitness();
};
