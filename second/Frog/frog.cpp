#include "./frog.h"

bool operator>(const Frog& r1, const Frog& r2) {
	if (r1.value > r2.value) return true;
	return false;
}

void Frog::sort(vector<Frog> ranas) {
	for( int i = 0; i < ranas.size(); i++ ) {
		if( ranas[i] > ranas[i+1]) {
			auto aux = ranas[i+1];
			ranas[i+1] = ranas[i];
			ranas[i] = aux;
		}
	}
}
