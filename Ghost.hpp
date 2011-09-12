#ifndef __GHOST_HPP
	#define __GHOST_HPP

#include <GL/gl.h>

class Ghost {
public:
	Ghost(float _x, float _z);
	static void init(int _redghostlist);
	void draw(float dirdeg);

	float x,z;
	static int redghostlist;
private:

};

#endif
