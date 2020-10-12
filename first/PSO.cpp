#include "PSO.h"

Particle::Particle() {
	Particle::counter();
	Particle::setGlobal();
	this->speedx = this->speedy = 0;

	this->posx = -VMAX + rand() % (VMAX + VMAX + 1);
	this->posy = -VMAX + rand() % (VMAX + VMAX + 1);
}

void Particle::setPosX(float x) { this->posx = x; }

void Particle::setPosY(float x) { this->posy = x; }

void Particle::setSpeedX(float x) { this->speedx = x; }

void Particle::setSpeedY(float x) { this->speedy = x; }

float Particle::getPosX() { return this->posx; }

float Particle::getPosY() { return this->posy; }

float Particle::getSpeedX() { return this->speedx; }

float Particle::getSpeedY() { return this->speedy; }

float Particle::getOnX(int i) { return this->x[i]; }

float Particle::getOnB(int i) { return this->b[i]; }

int Particle::getID() { return this->id; }

float Particle::speed(int t, int f1, int f2, int e1, int e2, float *g) {
	if (t > 1)
		return speed(t - 1, f1, f2, e1, e2, g) + f1 * e1 * (this->getOnB(t) - this->getOnX(t)) +
		       f2 * e2 * (g[t] - this->getOnX(t));
	/* return speed(v, t - 1, f1, f2, e1, e2, g) + f1 * e1 * (v.b[t] - v.x[t]) + f2 * e2 * (g[t] - v.x[t]); */
	else
		return 1;
}

float Particle::position(int t, float *x, float *speed) {
	if (t > 1)
		return position(t - 1, x, speed) + speed[t - 1];
	else
		return 1;
}

int testParticle() { return 0; }

void Particle::getParamenters() {
	std::cout << "--------------------\n";
	std::cout << "particle " << this->getID() << "\n";
	std::cout << "Vx = " << this->getSpeedX() << ", Vy = " << getSpeedY() << "\nPosx = " << getPosX()
		  << " , PosY = " << getPosX() << std::endl;
	std::for_each(this->global.begin(), this->global.end(), [](float i) { std::cout << "v = " << i << std::endl; });
	this->global.rbegin();
	std::cout << "\n--------------------";
}
