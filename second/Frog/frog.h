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
	void enhance(vector<float> D);
	void random_position();

       public:
	typedef vector<Frog> _rowFrogs;
	static vector<_rowFrogs> _columFrogs;
	static vector<float> best_global_position_from_memeplexer;
	static vector<Frog> global_best;
	static float best_global_value_from_memeplexer;

	Frog(int x, int y, int z) : Particle(x, y, z) {}
	Frog();
	~Frog() {}
	void setMeme_id(int);
	int getMeme_id();
	void worst_particle(Frog &);
	vector<float> getposition();

	static void best_value_position_from_memeplexer(Frog);
	static vector<_rowFrogs> meme(vector<Frog> &ranas);

	void worst_value_position(Frog &);
	static void local_search(Frog &best_particle, Frog &worst_particle);

	void best_local_value_postion(Frog);
	friend bool operator>(const Frog &, const Frog &);
	friend bool operator<(const Frog &, const Frog &);
	friend vector<float> operator+(const vector<float> &, const vector<float> &);
	virtual void getParameters();
	virtual void update_speed(vector<float>);
};
