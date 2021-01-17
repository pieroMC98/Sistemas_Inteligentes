#ifndef _SCOUT_H
#define _SCOUT_H
#include "../Bee.h"

class Exploradora : public Bee {
	public:
		Bee* run(Source&,Source) override;
};
#endif
