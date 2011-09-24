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

	float lampTime;
	bool lampOn;

	bool init();
	void loop();

	void draw();
	void draw2D();
	void drawWalls();
	void fade(int dir, float fadetime);

	void pushOrtho();
	void popOrtho();

	bool loadResources();
	void compileDisplayLists();

	std::vector<Ghost>::iterator git;
	std::vector<Pickup>::iterator dit;
	std::vector<Particle>::iterator pit;
};

#endif
