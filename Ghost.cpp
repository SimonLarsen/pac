#include "Ghost.hpp"

GLuint Ghost::redghostlist;

Ghost::Ghost(float _x, float _z){
	x = _x;
	z = _z;
	dir = rand() % 4;
	moved = 0.f;
}

void Ghost::init(GLuint _redghostlist){
	redghostlist = _redghostlist;
}

void Ghost::update(float dt, Map& map){

}

void Ghost::draw(float dirdeg){
	glPushMatrix();
	glTranslatef(x,0,z);
	glRotatef(-dirdeg,0,1,0);
	glCallList(redghostlist);
	glPopMatrix();
}
