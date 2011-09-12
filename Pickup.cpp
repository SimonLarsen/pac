#include "Pickup.hpp"

int Pickup::smalldotlist;

Pickup::Pickup(float _x, float _z, PickupType _type){
	x = _x;
	z = _z;
	type = _type;
}

void Pickup::init(int _smalldotlist){
	smalldotlist = _smalldotlist;
}

void Pickup::draw(float dirdeg){
	glPushMatrix();
	glTranslatef(x,0,z);
	glRotatef(-dirdeg,0,1,0);
	glCallList(smalldotlist+type);
	glPopMatrix();
}
