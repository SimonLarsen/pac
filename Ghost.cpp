#include "Ghost.hpp"

GLuint Ghost::redghostlist;

Ghost::Ghost(int _x, int _z, int _color){
	x = _x+0.5f;
	z = _z+0.5f;
	dir = 5;
	moved = 1.f;
	color = _color;
	scaredTime = 0.f;
}

void Ghost::init(GLuint _redghostlist){
	redghostlist = _redghostlist;
}

void Ghost::update(float dt, Map& map){
	bool newDir = false;
	float toMove;

	if(scaredTime > 0.f){
		scaredTime -= dt;
		toMove = dt*SCAREDSPEED;
	}
	else{
		toMove = dt*MOVESPEED;
	}

	if(moved + toMove > 1.0f){
		toMove = moved + toMove - 1.0f;
		moved = 0.f;
		newDir = true;
	}
	moved += toMove;

	switch(dir){
		case 0: z -= toMove; break;
		case 1: x += toMove; break;
		case 2: z += toMove; break;
		case 3: x -= toMove; break;
	}

	if(newDir){
		int badDir;
		if(map.canMove(xmask(x,dir),zmask(z,dir))){
			badDir = (dir+2)%4;
		}
		else{
			badDir = dir;
		}

		dir = rand() % 4;
		for(int i = 0; i < 4; ++i) {
			if(dir != badDir && map.canMove(xmask(x,dir),zmask(z,dir))){
				return;
			}
			dir = (dir+1)%4;
		}
	}
}

void Ghost::setScared(){
	scaredTime = SCAREDTIME;
}

int Ghost::xmask(int nx, int ndir){
	if(ndir == 1)
		return nx+1;
	if(ndir == 3)
		return nx-1;
	return nx;
}

int Ghost::zmask(int nz, int ndir){
	if(ndir == 0)
		return nz-1;
	if(dir == 2)
		return nz+1;
	return nz;
}

void Ghost::draw(float dirdeg){
	glPushMatrix();
	glTranslatef(x,0,z);
	glRotatef(-dirdeg,0,1,0);
	if(scaredTime > 0.f){
		if(scaredTime > 3.f || (int)(scaredTime*10.f)%2 == 0){
			glCallList(redghostlist+4);
		}
		else{	
			glCallList(redghostlist+color);
		}
	}
	else{
		glCallList(redghostlist+color);
	}
	glPopMatrix();
}
