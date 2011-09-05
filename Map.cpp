#include "Map.hpp"

Map::Map(){
	w = 0;
	h = 0;
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

bool Map::readFromImage(const char* filename){
	// TODO: Implement
}
