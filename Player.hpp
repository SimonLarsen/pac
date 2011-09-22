#ifndef __PLAYER_HPP
	#define __PLAYER_HPP

#include <SFML/Window.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include "Pickup.hpp"
#include "defines.hpp"
#include "Map.hpp"
#include "SndMgr.hpp"

class Player {
public:
	float x,y,z; // coords
	float xdir,xdirdeg; // dir in radians, dir in degrees
	float ydir,ydirdeg;
	float ghostDist;
	int state; // 0 = alive, 1 = dead/dying
	float bop, killer;

	Player();

	void update(float dt, Map& map, sf::Window& window, bool hasFocus, SndMgr& sndmgr);
	int collideDots(std::vector<Pickup>& dots, SndMgr& sndmgr);
	void collideGhosts(std::vector<Ghost>& ghosts, SndMgr& sndmgr);
	void drawEffects();

	const static float WALKSPEED = 2.0f;
	const static float STRAFESPEED = 1.5f;
	const static float TURNSPEED = 3.f;
};

#endif
