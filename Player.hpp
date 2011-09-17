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
	float xdir,xdirdeg; // dir in radians, dir in degrees
	float ydir,ydirdeg;

	Player();
	Player(float x, float y, float z, float xdir);

	void update(float dt, Map& map, sf::Window& window, bool hasFocus);
	int collideDots(std::vector<Pickup>& dots);

	const static float WALKSPEED = 2.0f;
	const static float STRAFESPEED = 1.5f;
	const static float TURNSPEED = 3.f;
};

#endif
