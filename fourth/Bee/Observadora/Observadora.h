#include "../Bee.h"
#include "../Empleada/Empleada.h"

class Observadora : public Bee {
	static Source prob;
       public:
	Bee* run(Source&, Source) override;
	static void choose_source(vector<Source>);
	Observadora(int x, int y, int z) : Bee(x, y, z) {}
	Observadora() : Bee() {}
	virtual ~Observadora() {}
};
