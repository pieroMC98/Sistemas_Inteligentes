#include "../Bee.h"
#include "../Empleada/Empleada.h"

class Observadora : public Bee {
	static Source prob;

       public:
	Bee* run(Source, Source);
	static void choose_source(vector<Source>);
	Observadora() : Bee() {}
	virtual ~Observadora() {}
};
