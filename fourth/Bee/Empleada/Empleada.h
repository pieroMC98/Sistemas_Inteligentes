#include "../Bee.h"

class Empleada : public Bee {
	Source fuente_candidata(Source, Source);
	vector<float> neighbor(Source);

       public:
	Empleada(int x, int y, int z) : Bee(x, y, z) {}
	Empleada() : Bee() {}
	void run(Source &);
	virtual ~Empleada() {}
};
