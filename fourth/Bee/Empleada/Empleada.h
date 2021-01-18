#include "../Bee.h"
#include "../Exploradora/Exploradora.h"

class Empleada : public Bee {
	Source fuente_candidata(Source, Source);

       public:
	Empleada(Source xi) { this->xi = xi; }
	Bee* run(Source&, Source) override;
	void getParameters() override;
	virtual ~Empleada() {}
};
