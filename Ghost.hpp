#ifndef __GHOST_HPP
	#define __GHOST_HPP

#include <GL/gl.h>
#include <cstdlib>
#include <cmath>
class Ghost;
#include "Map.hpp"

class Ghost {
public:
	Ghost(int x, int z, int color);
	static void init(GLuint _redghostlist);
	void draw(float dirdeg);
	void update(float dt, Map& map);
	void setScared();

	float x,z, scaredTime;
	int dir, color;
private:
	static GLuint redghostlist;
	float moved;
	int xmask(int x, int dir);
	int zmask(int z, int dir);

	const static float MOVESPEED = 2.0f;
	const static float SCAREDSPEED = 1.25f;
	const static float SCAREDTIME = 10.f;
};

#endif
