#include "Map.hpp"

Map::Map(){
	w = 0;
	h = 0;
	numDots = 0;
	numBigDots = 0;
	startx = 0.5f;
	startz = 0.5f;
	data = 0;
}

Map::~Map(){
	delete[] data;
}

bool Map::readFromImage(const char* filename, std::vector<Pickup>& dots){
	sf::Image img;
	if(img.LoadFromFile(filename) == false){
		return false;
	}
	w = img.GetWidth();
	h = img.GetHeight();

	data = new char[w*h];
	for(int iy = 0; iy < h; ++iy){
		for(int ix = 0; ix < w; ++ix){
			sf::Color p = img.GetPixel(ix,iy);
			if(p == sf::Color::Black){
				data[ix+iy*w] = 0;
			}
			else if(p == sf::Color::White){
				data[ix+iy*w] = 0;
				dots.push_back(Pickup(ix+0.5f,iy+0.5f,pickupSmall));
			}
			else if(p == sf::Color::Blue){
				data[ix+iy*w] = 1;
			}
			else if (p == sf::Color::Red){
				data[ix+iy*w] = 0;
				startx = ix+0.5f;
				startz = iy+0.5f;
			}
			else if (p == sf::Color::Yellow){
				data[ix+iy*w] = 2;
				dots.push_back(Pickup(ix+0.5f,iy+0.5f,pickupSmall));
				numDots++;
			}
			else if (p == sf::Color::Green){
				data[ix+iy*w] = 0;
				dots.push_back(Pickup(ix+0.5f,iy+0.5f,pickupBig));
				numBigDots++;
			}
			else if(p == sf::Color::Magenta){
				data[ix+iy*w] = 3;
			}
		}
	}

	return true;
}

bool Map::canMove(int x, int y){
	if(data[x+y*w] != 1)
		return true;
	else
		return false;
}

bool Map::canMove(int index){
	if(data[index] != 1)
		return true;
	else
		return false;
}

char Map::get(int x, int y){
	return data[x+y*w];
}
