#include "../../first/Particle/PSO.h"
using namespace std;
class Frog : public Particle {
	int meme_id;

	static void sort(vector<Frog>&);
	static void memeplexer_id(vector<Frog>&);
	static void memeplexer(vector<Frog> ranas) {
		for (size_t i = 0; i < ranas.size(); i++)
			if (ranas[i].getMeme_id() == 1)
				Frog::_columFrogs[0].push_back(ranas[i]);
			else
				Frog::_columFrogs[1].push_back(ranas[i]);
	}

       public:
	typedef vector<Frog> _rowFrogs;
	static vector<_rowFrogs> _columFrogs;
	Frog() : Particle() {}
	Frog(int x, int y, int z) : Particle(x, y, z) {}
	~Frog() {}
	void setMeme_id(int i);
	int getMeme_id();

	static vector<vector<Frog>> meme(vector<Frog> ranas) {
		for_each(Frog::_columFrogs.begin(), Frog::_columFrogs.end(), [=](vector<Frog>& x) { x.resize(4); });
		Frog::sort(ranas);
		Frog::memeplexer_id(ranas);
		Frog::memeplexer(ranas);
		return Frog::_columFrogs;
	}

	friend bool operator>(const Frog&, const Frog&);
	virtual void getParameters();
};
