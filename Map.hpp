#ifndef __MAP_HPP
	#define __MAP_HPP

//#include <string>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Pickup.hpp"

class Map {
public:
	Map();
	~Map();
	int w,h;
	float startx,startz;
	char* data;

	bool readFromImage(const char* filename, std::vector<Pickup>& dots);
};

#endif
