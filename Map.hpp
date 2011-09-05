#ifndef __MAP_HPP
	#define __MAP_HPP

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

class Map {
public:
	Map();
	Map(int _w, int _h, char* _data);
	~Map();
	int w,h;
	char* data;

	bool readFromFile(const char* filename);
	bool readFromImage(const char* filename);
};

#endif
