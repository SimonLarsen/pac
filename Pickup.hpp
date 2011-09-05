#ifndef __PICKUP_HPP
	#define __PICKUP_HPP

enum PickupType {pickHealth, pickAmmo};

class Pickup {
public:
	Pickup(int _x, int _y, PickupType _type);
	int x,y;
	PickupType type;
};

#endif
