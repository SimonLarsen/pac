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

void Player::update(float dt, Map& map, sf::Window& window, bool hasFocus){
	float nx = x;
	float nz = z;
	bool moved = false;

	// Check keyboard input
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Up)
	|| sf::Keyboard::IsKeyPressed(sf::Keyboard::W)){
		nx = x + sin(dir)*WALKSPEED*dt;
		nz = z - cos(dir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Down)
	|| sf::Keyboard::IsKeyPressed(sf::Keyboard::S)){
		nx = nx - sin(dir)*WALKSPEED*dt;
		nz = nz + cos(dir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::A)){
		nx = nx - cos(dir)*STRAFESPEED*dt;
		nz = nz - sin(dir)*STRAFESPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::D)){
		nx = nx + cos(dir)*STRAFESPEED*dt;
		nz = nz + sin(dir)*STRAFESPEED*dt;
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

	// Check mouse input
	if(hasFocus){
		sf::Vector2i pos = sf::Mouse::GetPosition(window);
		if(pos.x != SCREEN_WIDTH/2){
			float diff = (float)(SCREEN_WIDTH/2 - pos.x);
			dir -= diff*dt;
			dirdeg = dir * RADDEG;
		}
		sf::Mouse::SetPosition(sf::Vector2i(SCREEN_WIDTH/2,SCREEN_HEIGHT/2), window);
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

void Player::collideDots(std::vector<Pickup>& dots){
	std::vector<Pickup>::iterator it;
	for(it = dots.end(); it >= dots.begin(); it--){
		float dist = pow((float)(x-it->x),2) + pow((float)(z-it->z),2);
		if(dist < 0.25f){
			dots.erase(it);
		}
	}
}
