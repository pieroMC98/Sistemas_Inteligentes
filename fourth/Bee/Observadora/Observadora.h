#include "../Bee.h"

class Observadora : public Bee {
	Source choose_source(Source);
	static float sumatorio;

       public:
	void run(Source&) override;
	static void sum_S(vector<Source>);
	Observadora(int x, int y, int z) : Bee(x, y, z) {}
	Observadora() : Bee() {}
	virtual ~Observadora() {}
};
