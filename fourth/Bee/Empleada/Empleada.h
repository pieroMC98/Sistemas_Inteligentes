#include "../Bee.h"
#include "../Exploradora/Exploradora.h"

class Empleada : public Bee {
	Source fuente_candidata(Source);

       public:
	Empleada(Source xi) {
		this->xi = xi;
		this->call_back = Source::c_b;
		this->id = Bee::ID++;
		this->xi.limiti = 0;
	}
	Bee* run(Source&, Source) override;
	void getParameters() override;
	virtual ~Empleada() {}
};
