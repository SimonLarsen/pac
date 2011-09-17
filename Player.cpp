#include "Player.hpp"

Player::Player(){
	x = 0.f;
	y = 0.6f;
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
		// Check collision with walls
		int tl,tr,bl,br;
		// Check x axis
		tl = floor(nx-0.25)+floor(z-0.25)*map.w;
		tr = floor(nx+0.25)+floor(z-0.25)*map.w;
		bl = floor(nx-0.25)+floor(z+0.25)*map.w;
		br = floor(nx+0.25)+floor(z+0.25)*map.w;
		//if(!map.isWall(tl) && !map.isWall(tr) && !map.isWall(bl) && !map.isWall(br)){
		if(map.canMove(nx-0.25,z-0.25) && map.canMove(nx+0.25,z-0.25) && map.canMove(nx-0.25,z+0.25) && map.canMove(nx+0.25,z+0.25)){
			x = nx;
		}

		tl = floor(x-0.25)+floor(nz-0.25)*map.w;
		tr = floor(x+0.25)+floor(nz-0.25)*map.w;
		bl = floor(x-0.25)+floor(nz+0.25)*map.w;
		br = floor(x+0.25)+floor(nz+0.25)*map.w;
		if(map.canMove(tl) && map.canMove(tr) && map.canMove(bl) && map.canMove(br)){
			z = nz;
		}
		// Wrap if through portal
		if(x < 0.3f){ x = map.w-0.5f; }
		else if(x > map.w-0.3f){ x = 0.5f; }
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
