#ifndef __PICKUP_HPP
	#define __PICKUP_HPP

#include "GL/gl.h"

enum PickupType {pickupSmall, pickupBig};

class Pickup {
public:
	Pickup(float x, float y, PickupType type);
	float x,z;
	PickupType type;
	static int smalldotlist;

	static void init(int _smalldotlist);
	void draw(float dirdeg);
};

#endif
