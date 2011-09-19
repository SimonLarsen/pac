#ifndef __MAP_HPP
	#define __MAP_HPP

#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Pickup.hpp"
class Map;
#include "Ghost.hpp"

class Map {
public:
	Map();
	~Map();
	int w,h, numDots, numBigDots;
	float startx,startz;
	char* data;

	bool readFromImage(const char* filename, std::vector<Pickup>& dots, std::vector<Ghost>& ghosts);

	bool canMove(int x, int y);
	bool canMove(int index);
	char get(int x, int y);
};

#endif
