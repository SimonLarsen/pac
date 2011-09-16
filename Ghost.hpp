#ifndef __GHOST_HPP
	#define __GHOST_HPP

#include <GL/gl.h>
#include <cstdlib>
#include <cmath>
#include "Map.hpp"

#include <iostream>

class Ghost {
public:
	Ghost(float _x, float _z, int _color);
	static void init(GLuint _redghostlist);
	void draw(float dirdeg);
	void update(float dt,  Map& map);

	float x,z;
	int dir, color;
private:
	static GLuint redghostlist;
	float moved;
	int xmask(int _x, int _dir);
	int zmask(int _z, int _dir);

	const static float MOVESPEED = 0.5f;
};

#endif
