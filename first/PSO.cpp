#include "PSO.h"

Particle::Particle() {
	Particle::counter();
	Particle::setGlobal();
	Particle::dimension();

	this->speed.resize(this->Dimension);
	this->position.resize(this->Dimension);

	std::for_each(this->position.begin(), this->position.end(), [](float &x) {
			 x = -VMAX + rand() % (VMAX + VMAX + 1);
			});
}

float Particle::getOnX(int i) { return this->x[i]; }

float Particle::getOnB(int i) { return this->b[i]; }

int Particle::getID() { return this->id; }

float Particle::speed_test(int t, int f1, int f2, int e1, int e2, float *g) {
	if (t > 1)
		return speed_test(t - 1, f1, f2, e1, e2, g) + f1 * e1 * (this->getOnB(t) - this->getOnX(t)) +
		       f2 * e2 * (g[t] - this->getOnX(t));
	/* return speed(v, t - 1, f1, f2, e1, e2, g) + f1 * e1 * (v.b[t] - v.x[t]) + f2 * e2 * (g[t] - v.x[t]); */
	else
		return 1;
}

float Particle::pos_test(int t, float *x, float *speed){
	if (t > 1)
		return pos_test(t - 1, x, speed) + speed[t - 1];
	else
		return 1;
}

float Particle::target_function(std::vector<float> x, int i){
	if( i > 0)
		return pow(target_function(x,i-1),2);
	else
		return 1;
	
}
int Particle::testParticle(int f, int optimization) { 
	this->value = target_function(this->position,0);
	return 0;
}

float Particle::module_vector(std::vector<float> v, int i){
	if( i > 0 )
		return sqrtf((module_vector(v,i-1),2) + pow(v[i],2));
	else
		return pow(v[0],2);

}
void Particle::getParamenters() {
	int j = 0;
	std::cout << "--------------------\n";
	std::cout << "particle " << this->getID() << "\n";
	for(auto i : this->position){
		std::cout<<"pos "<<j<<" = "<<i<<std::endl;
		++j;
	}
	j = 0;
	for(auto i : this->speed){
		std::cout<<"V "<<j<<" = "<<i<<std::endl;
		++j;
	}
	
	std::cout<<"global array == \n";
	std::for_each(this->global.begin(), this->global.end(), [](float i) { std::cout << "v = " << i << std::endl; });
	std::cout << "\n--------------------";
}
