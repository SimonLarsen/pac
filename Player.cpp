#include "Player.hpp"

Player::Player(){
	x = 0.f;
	y = 0.f;
	z = 0.f;
	xdir = 0.f;
	xdirdeg = 0.f;
	ydir = 0.f;
	ydirdeg = 0.f;
}

Player::Player(float _x, float _y, float _z, float _xdir){
	x = _x;
	y = _y;
	z = _z;
	xdir = _xdir;
	xdirdeg = xdir * RADDEG;
	ydir = 0.f;
	ydirdeg = 0.f;
}

void Player::update(float dt, Map& map, sf::Window& window, bool hasFocus){
	float nx = x;
	float nz = z;
	bool moved = false;

	// Check keyboard input
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Up)
	|| sf::Keyboard::IsKeyPressed(sf::Keyboard::W)){
		nx = nx + sin(xdir)*WALKSPEED*dt;
		nz = nz - cos(xdir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Down)
	|| sf::Keyboard::IsKeyPressed(sf::Keyboard::S)){
		nx = nx - sin(xdir)*WALKSPEED*dt;
		nz = nz + cos(xdir)*WALKSPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::A)){
		nx = nx - cos(xdir)*STRAFESPEED*dt;
		nz = nz - sin(xdir)*STRAFESPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::D)){
		nx = nx + cos(xdir)*STRAFESPEED*dt;
		nz = nz + sin(xdir)*STRAFESPEED*dt;
		moved = true;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Left)){
		xdir -= TURNSPEED*dt;
		xdirdeg = xdir * RADDEG;
	}
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::Right)){
		xdir += TURNSPEED*dt;
		xdirdeg = xdir * RADDEG;
	}

	// Check mouse input
	if(hasFocus){
		sf::Vector2i pos = sf::Mouse::GetPosition(window);
		if(pos.x != SCREEN_WIDTH/2){
			float diff = (float)(SCREEN_WIDTH/2 - pos.x);
			xdir -= diff*dt;
			xdirdeg = xdir * RADDEG;
		}
		if(pos.y != SCREEN_HEIGHT/2){
			float diff = (float)(SCREEN_HEIGHT/2 - pos.y);
			ydir -= diff*dt;
			if(ydir < -PI/2.f){ ydir = -PI/2.f; }
			else if(ydir > PI/2.f){ ydir = PI/2.f; }
			ydirdeg = ydir * RADDEG;
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
		if(map.data[tl] != 1 && map.data[tr] != 1 && map.data[bl] != 1 && map.data[br] != 1){
			x = nx;
		}

		tl = floor(x-0.25)+floor(nz-0.25)*map.w;
		tr = floor(x+0.25)+floor(nz-0.25)*map.w;
		bl = floor(x-0.25)+floor(nz+0.25)*map.w;
		br = floor(x+0.25)+floor(nz+0.25)*map.w;
		if(map.data[tl] != 1 && map.data[tr] != 1 && map.data[bl] != 1 && map.data[br] != 1){
			z = nz;
		}
	}
}

void Player::collideDots(std::vector<Pickup>& dots){
	std::vector<Pickup>::iterator it;
	for(it = dots.end(); it >= dots.begin(); it--){
		float dist = pow((float)(x-it->x),2) + pow((float)(z-it->z),2);
		if(dist < 0.15f){
			dots.erase(it);
		}
	}
}
