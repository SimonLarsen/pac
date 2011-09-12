#include "Map.hpp"

Map::Map(){
	w = 0;
	h = 0;
	startx = 0.5f;
	startz = 0.5f;
	data = 0;
}
Map::Map(int _w, int _h, char* _data){
	w = _w;
	h = _h;
	data = _data;
}

Map::~Map(){
	delete[] data;
}

bool Map::readFromFile(const char* filename){
	std::ifstream ifs(filename,std::ios::binary);
	if(ifs.is_open() == false){
		return false;
	}

	int header[2];
	ifs.read((char*)&header,sizeof(header));
	w = header[0];
	h = header[1];
	data = new char[w*h];
	ifs.read(data,w*h);
	ifs.close();
	return true;
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
			else if (p == sf::Color::Magenta){
				data[ix+iy*w] = 0;
				startx = ix+0.5f;
				startz = iy+0.5f;
			}
		}
	}

	return true;
}
