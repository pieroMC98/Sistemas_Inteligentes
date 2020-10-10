#include "PSO.h"

Particle::Particle() {
	Particle::counter();
	this->speedx = VMIN + rand() % (VMAX - VMIN + 1);
	this->speedy = VMIN + rand() % (VMAX - VMIN + 1);

	this->posx = VMIN + rand() % (VMAX - VMIN + 1);
	this->posy = VMIN + rand() % (VMAX - VMIN + 1);
	this->b = (float *)calloc(10, sizeof(float));
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
float Particle::speed(Particle v, int t, int f1, int f2, int e1, int e2, float *g) {
	if (t > 1)
		return speed(v, t - 1, f1, f2, e1, e2, g) + f1 * e1 * (v.getOnB(t) - v.getOnX(t)) +
		       f2 * e2 * (g[t] - v.getOnX(t));
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

void Particle::getParamenters() {
	std::cout << "--------------------\n";
	std::cout << "particle " << this->getID() << "\n";
	std::cout << "Vx = " << this->getSpeedX() << ", Vy = " << getSpeedY() << "\nPosx = " << getPosX()
		  << " , PosY = " << getPosX();
	std::cout << "\n--------------------";
}  // namespace Particle
