#include "../second/Frog/frog.h"
int main(int argc, char *argv[]) {
	typedef vector<Frog> row_frogs;
	vector<row_frogs> memeplexer(4, row_frogs(4, *(new Frog)));
	return 0;
}
