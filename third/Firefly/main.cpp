#include "Firefly.h"
int main(int argc, char *argv[]) {

	vector<float> i = {2,3,4};
	vector<float> j = {5,4,4};
	vector<float> rt = i + j;
	for( size_t i = 0; i < rt.size(); i++ ) {
		cout<<" "<<rt.at(i);
	}
	return EXIT_SUCCESS; }
