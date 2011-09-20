#ifndef __PARTICLE_HPP
#define __PARTICLE_HPP

#include <GL/gl.h>
#include <cmath>

enum ParticleType {particleKillGhost};

class Particle {
public:
	Particle(float x, float y, float z, ParticleType type);
	float x,y,z;
	float frame;
	bool alive;
	ParticleType type;

	void update(float dt);
	void draw(float dirdeg);
};

#endif
