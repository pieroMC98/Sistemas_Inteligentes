#include "../Bee.h"
#include "../Empleada/Empleada.h"

class Observadora : public Bee {
       public:
	static Source prob;
	Bee* run();
	static void choose_source(vector<Source>);
	Observadora() : Bee() {}
	virtual ~Observadora() {}
};
