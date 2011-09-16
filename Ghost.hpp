#ifndef __GHOST_HPP
	#define __GHOST_HPP

#include <GL/gl.h>
#include <cstdlib>
#include <cmath>
#include "Map.hpp"

#include <iostream>

class Ghost {
public:
	Ghost(int _x, int _z, int _color);
	static void init(GLuint _redghostlist);
	void draw(float dirdeg);
	void update(float dt,  Map& map);
	void setScared();

	float x,z, scaredTime;
	int dir, color;
private:
	static GLuint redghostlist;
	float moved;
	int xmask(int _x, int _dir);
	int zmask(int _z, int _dir);

	const static float MOVESPEED = 2.0f;
	const static float SCAREDSPEED = 1.25f;
	const static float SCAREDTIME = 10.f;
};

#endif
