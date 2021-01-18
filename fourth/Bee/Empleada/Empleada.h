#include "../Bee.h"
#include "../Exploradora/Exploradora.h"

class Empleada : public Bee {
	Source fuente_candidata(Source, Source);

       public:
	Empleada() : Bee() {}
	Bee* run(Source&, Source) override;
	virtual ~Empleada() {}
};
