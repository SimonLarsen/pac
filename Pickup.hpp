#ifndef __PICKUP_HPP
	#define __PICKUP_HPP

enum PickupType {pickupSmall, pickupBig};

class Pickup {
public:
	Pickup(float _x, float _y, PickupType _type);
	float x,z;
	PickupType type;
};

#endif
