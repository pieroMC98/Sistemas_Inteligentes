#include "../Bee.h"
#include "../Exploradora/Exploradora.h"

class Empleada : public Bee {
	Source fuente_candidata(Source, Source);

       public:
	Empleada(int x, int y, int z) : Bee(x, y, z) {}
	Empleada() : Bee() {}
	Bee* run(Source &, Source) override;
	virtual ~Empleada() {}
};
