#include "./frog.h"

bool operator>(const Frog& r1, const Frog& r2) {
	if (r1.value > r2.value) return true;
	return false;
}

void Frog::sort(vector<Frog>& ranas) {
	for (size_t i = 1; i < ranas.size(); i++) {
		if (ranas[i - 1] > ranas[i]) {
			Frog aux = ranas[i];
			ranas[i] = ranas[i - 1];
			ranas[i - 1] = aux;
		}
	}
}

void Frog::memeplexer(vector<Frog>& ranas) {
	for (size_t i = 0; i < ranas.size(); i++) {
		if (!i % 2)
			ranas[i].meme_id = 1;
		else
			ranas[i].meme_id = 2;
	}
}

void Frog::getParameters(){
	Particle::getParameters();
	cout<<"memeplexer group "<<this->meme_id<<endl;
}
