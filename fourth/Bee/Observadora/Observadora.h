#include "../Bee.h"

class Observadora : private Bee {
	Source choose_source(Source);
	static float sumatorio;

       public:
	void run(Source) override;
	static void sum_S(vector<Source>);
};
