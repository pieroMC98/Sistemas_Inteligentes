#include "../../Template/template.h"
#include "../../first/Particle/PSO.h"

class Source : private Particle {
	void gen_solves_array();
	static float xmin, xmax;
	std::vector<Source> solves_array;

       public:
	static int D;
	int limiti;
	Source();
	Source(float);
	Source(int p, int d, int l) : Particle(p, d, l) {}
	virtual ~Source() {}
	std::vector<float> getPosition();
	void getParameters() override;
	void setPosition(std::vector<float>);
	float getFitness();
	std::vector<Source> getArraySolve();
	void setArraySolve(std::vector<Source>);
	// clang-format off
	friend bool operator> <>(const Source &, const Source &);
	friend bool operator< <>(const Source &, const Source &);
	// clang-format on
};
