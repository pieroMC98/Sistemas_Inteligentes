#include "../../first/Particle/PSO.h"
using namespace std;

class Frog : public Particle {
	int meme_id;
	std::vector<float> worst_global_position;
	float worst_global_value;

	static void sort(vector<Frog> &);
	static void memeplexer_id(vector<Frog> &);
	static void memeplexer(vector<Frog>);
	static void set_value_position_frogs(vector<Frog> &);

       public:
	typedef vector<Frog> _rowFrogs;
	static vector<_rowFrogs> _columFrogs;
	static vector<float> best_global_position_frogs;
	static float best_global_value_forgs;

	Frog() : Particle() {}
	Frog(int x, int y, int z) : Particle(x, y, z) {}
	~Frog() {}
	void setMeme_id(int);
	int getMeme_id();
	void worst_particle(Frog &);

	static vector<vector<Frog>> meme(vector<Frog> &ranas) {
		Frog::sort(ranas);
		Frog::memeplexer_id(ranas);
		Frog::memeplexer(ranas);
		return Frog::_columFrogs;
	}

	void worst_value_position(Frog &);
	void slf(Frog &);
	void local_search(Frog &, Frog &);
	float enhance(Frog);

	void best_local_value_postion(Frog);
	friend bool operator>(const Frog &, const Frog &);
	friend bool operator<(const Frog &, const Frog &);
	virtual void getParameters();
};
