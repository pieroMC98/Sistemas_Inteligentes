#ifndef _SOURCE_H
#define _SOURCE_H
#include "../../Template/template.h"
#include "../../first/Particle/PSO.h"

class Source : private Particle {
	void gen_solves_array();
	static float xmin, xmax;
	static int D;
	std::vector<Source> solves_array;

       public:
	static void setStatics(int p,int d, float l);
	static int sol;
	int limiti;
	Source() : Particle (){
		std::cout<<" "<<this->Dimension;
		std::cout<<" "<<this->limits;
		std::cout<<" "<<this->process;
		std::cout<<" "<<Source::sol;
		//this->setArraySolve();
		//for (int i= 0; i < Source::sol; i++) this->solves_array.push_back(Source(this->random_float(0, 1)));
	};
	Source(float);
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
#endif
//int Particle::P , Particle::ID, Particle::D;
