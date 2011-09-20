#ifndef __GAME_HPP
	#define __GAME_HPP

#include "defines.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <cstdlib>
#include "Player.hpp"
#include "Ghost.hpp"
#include "Map.hpp"
#include "Pickup.hpp"
#include "Particle.hpp"

class Game {
public:
	// Display lists
	GLuint walls,floor,ceiling;
	GLuint lampfloor,lampceiling,lampceilingoff;
	GLuint smalldot,bigdot;
	GLuint redghost, blueghost, pinkghost, yellowghost, scaredghost;
	GLuint shadow, portal;

	std::vector<Pickup> dots;
	std::vector<Ghost> ghosts;
	std::vector<Particle> particles;

	sf::Texture tiles;
	sf::RenderWindow app;
	sf::Event event;
	sf::Clock clock;

	Map map;
	Player pl;
	SndMgr sndmgr;

	Game();
	int execute();

private:
	bool running, paused, hasFocus;
	float scaredTime;

	// lamp blinking stuff
	float lampTime;
	bool lampOn;

	bool init();
	void loop();
	bool loadResources();
	void compileDisplayLists();

	void drawWalls();
	void pushOrtho();
	void popOrtho();
};

#endif
