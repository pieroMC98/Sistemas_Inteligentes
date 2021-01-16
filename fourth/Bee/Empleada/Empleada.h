#include "../Bee.h"

class Empleada : private Bee {
	Source fuente_candidata(Source);

       public:
	Empleada(int x, int y, int z) : Bee(x, y, z) {}
	Empleada() : Bee() {}
	void run(Source &);
	virtual ~Empleada(){};
};
