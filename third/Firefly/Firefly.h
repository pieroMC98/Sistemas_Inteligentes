#include "../../second/Frog/frog.h"
#include "../../Template/template.h"
#include "../../Operator/operator.h"
class Firefly : public Frog {
	static float gamma, beta0;
	public:
	void sort(vector<Firefly>&);
	Firefly(int x, int y, int z) : Frog(x, y, z) {}
	Firefly() : Frog(){}
	virtual ~Firefly(){ };
	void update_position(std::vector<float>);
	float betai(vector<float>);
	friend bool operator> <>(const Firefly &, const Firefly &);
	friend bool operator< <>(const Firefly &, const Firefly &);
};
