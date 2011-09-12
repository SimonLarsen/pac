#include "Ghost.hpp"

int Ghost::redghostlist;

Ghost::Ghost(float _x, float _z){
	x = _x;
	z = _z;
}

void Ghost::init(int _redghostlist){
	redghostlist = _redghostlist;
}

void Ghost::draw(float dirdeg){
	glPushMatrix();
	glTranslatef(x,0,z);
	glRotatef(-dirdeg,0,1,0);
	glCallList(redghostlist);
	glPopMatrix();
}
