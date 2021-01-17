#include "../Bee.h"
#include "../Empleada/Empleada.h"

class Observadora : public Bee {
	float choose_source(Source);

       public:
	void run(Source&, Source);
	static void sum_S(vector<Source>);
	Observadora(int x, int y, int z) : Bee(x, y, z) {}
	Observadora() : Bee() {}
	virtual ~Observadora() {}
};
