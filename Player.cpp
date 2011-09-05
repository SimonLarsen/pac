#include "Player.hpp"

Player::Player(){
	x = 0.f;
	y = 0.f;
	z = 0.f;
	dir = 0.f;
	dirdeg = 0.f;
}

Player::Player(float _x, float _y, float _z, float _dir){
	x = _x;
	y = _y;
	z = _z;
	dir = _dir;
}

void Player::update(float dt, Map& map){
	float nx = x;
	float nz = z;
	bool moved = false;

	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Up)){
		nx = x + sin(dir)*WALKSPEED*dt;
		nz = z - cos(dir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Down)){
		nx = x - sin(dir)*WALKSPEED*dt;
		nz = z + cos(dir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::A)){
		nx = x - cos(dir)*WALKSPEED*dt;
		nz = z - sin(dir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::D)){
		nx = x + cos(dir)*WALKSPEED*dt;
		nz = z + sin(dir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Left)){
		dir -= TURNSPEED*dt;
		dirdeg = dir * RADDEG;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Right)){
		dir += TURNSPEED*dt;
		dirdeg = dir * RADDEG;
	}

	if(moved){
		int tl,tr,bl,br;
		// Check x axis
		tl = floor(nx-0.25)+floor(z-0.25)*map.w;
		tr = floor(nx+0.25)+floor(z-0.25)*map.w;
		bl = floor(nx-0.25)+floor(z+0.25)*map.w;
		br = floor(nx+0.25)+floor(z+0.25)*map.w;
		if(map.data[tl] == 0 && map.data[tr] == 0 && map.data[bl] == 0 && map.data[br] == 0){
			x = nx;
		}

		tl = floor(x-0.25)+floor(nz-0.25)*map.w;
		tr = floor(x+0.25)+floor(nz-0.25)*map.w;
		bl = floor(x-0.25)+floor(nz+0.25)*map.w;
		br = floor(x+0.25)+floor(nz+0.25)*map.w;
		if(map.data[tl] == 0 && map.data[tr] == 0 && map.data[bl] == 0 && map.data[br] == 0){
			z = nz;
		}
	}
}
