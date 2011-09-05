#ifndef __GAME_HPP
	#define __GAME_HPP

#include "defines.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Player.hpp"
#include "Map.hpp"

class Game {
public:
	GLuint walls,floor,healthpack,ammopack; // Display lists
	Map map;

	sf::Texture tiles;
	sf::Window app;
	sf::Event event;
	sf::Clock clock;
	Player pl;

	Game();
	int execute();

private:
	bool running;

	bool init();
	void loop();
	bool loadResources();
	void compileDisplayLists();
};

#endif
