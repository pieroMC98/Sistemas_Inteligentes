#include "../../Template/template.h"
#include "../../first/Particle/PSO.h"
using namespace std;

class Frog : public Particle {
       protected:
	int meme_id;
	std::vector<float> worst_global_position;
	float worst_global_value;

	static void sort(vector<Frog> &);
	static void memeplexer_id(vector<Frog> &);
	static void memeplexer(vector<Frog>);
	static void set_value_position_frogs(vector<Frog> &);
	void enhance(vector<float> D);
	void random_position();
	static void reset_meme();

       public:
	typedef vector<Frog> _rowFrogs;
	static vector<_rowFrogs> _columFrogs;
	static vector<float> best_global_position_from_memeplexer;
	static vector<Frog> global_best;
	static float best_global_value_from_memeplexer;

	// Frog(int x, int y, int z) : Particle(x, y, z) {}
	Frog();
	virtual ~Frog() {}
	void setMeme_id(int);
	int getMeme_id();
	void worst_particle(Frog &);
	vector<float> getposition();

	static void best_value_position_from_memeplexer(Frog);
	static vector<_rowFrogs> meme(vector<Frog> &);
	static vector<Frog> join_memeplexer(vector<_rowFrogs>);

	void worst_value_position(Frog &);
	static void local_search(Frog &, Frog &);

	void best_local_value_postion(Frog);
	// clang-format off
	friend bool operator> <>(const Frog &, const Frog &);
	friend bool operator< <>(const Frog &, const Frog &);
	// clang-format on

	void getParameters() override;
	void update_speed(vector<float>);
};
