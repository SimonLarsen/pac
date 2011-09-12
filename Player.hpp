#ifndef __PLAYER_HPP
	#define __PLAYER_HPP

#include <SFML/Window.hpp>
#include <math.h>
#include <vector>
#include "Pickup.hpp"
#include "defines.hpp"
#include "Map.hpp"

class Player {
public:
	float x,y,z; // coords
	float dir,dirdeg; // dir in radians, dir in degrees

	Player();
	Player(float _x, float _y, float _z, float _dir);

	void update(float dt, Map& map, sf::Window& window, bool hasFocus);
	void collideDots(std::vector<Pickup>& dots);

	const static float WALKSPEED = 3.f;
	const static float STRAFESPEED = 2.f;
	const static float TURNSPEED = 3.f;
};

#endif
