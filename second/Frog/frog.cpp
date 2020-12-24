#include "./frog.h"

vector<vector<Frog>> Frog::_columFrogs(2, vector<Frog>());

bool operator>(const Frog& r1, const Frog& r2) { return r1.value > r2.value ? true : false; }

void Frog::setMeme_id(int i) { this->meme_id = i; }

int Frog::getMeme_id() { return this->meme_id; }

void Frog::sort(vector<Frog>& ranas) {
	for (size_t i = 1; i < ranas.size(); i++)
		if (ranas[i - 1] > ranas[i]) {
			Frog aux = ranas[i];
			ranas[i] = ranas[i - 1];
			ranas[i - 1] = aux;
		}
}

void Frog::memeplexer_id(vector<Frog>& ranas) {
	for (size_t i = 0; i < ranas.size(); i++) ranas[i].setMeme_id(!(i % 2) ? 1 : 2);
}

void Frog::getParameters() {
	Particle::getParameters();
	cout << "memeplexer group " << this->meme_id << endl;
}
