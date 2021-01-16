#include "../../first/Particle/PSO.h"

class Source : private Particle {
	void gen_solves_array();
	static float xmin, xmax;
	std::vector<float> solves_array;

       public:
	int limiti;
	Source();
	Source(int p, int d, int l) : Particle(p, d, l) {}
	virtual ~Source() {}
	std::vector<float> getPosition();
	void getParameters() override;
	void setPosition(std::vector<float>);
	float getFitness();
	std::vector<float> getArraySolve();
};
