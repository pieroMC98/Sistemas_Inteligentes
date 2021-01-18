#ifndef _SOURCE_H
#define _SOURCE_H
#include "../../Template/template.h"
#include "../../first/Particle/PSO.h"
class Source : public Particle {
	void gen_solves_array();
	static float xmin, xmax;
	static int D;
	std::vector<Source> solves_array;

       public:
	void setCall(float (*)(std::vector<float>, int));
	static void setStatics(int p, int d, float l);
	void update_arraySolve();
	static int sol;
	int limiti;
	Source();
	Source(float (*)(std::vector<float>, int));
	Source(float);
	void run();
	virtual ~Source() {}
	std::vector<float> getPosition();
	void getParameters() override;
	void setPosition(std::vector<float>);
	void setArraySolve();
	float getFitness();
	std::vector<Source> getArraySolve();
	void setArraySolve(std::vector<Source>);
	// clang-format off
	friend bool operator> <>(const Source &, const Source &);
	friend bool operator< <>(const Source &, const Source &);
	// clang-format on
};
typedef float (*Call)(std::vector<float>, int);
#endif
