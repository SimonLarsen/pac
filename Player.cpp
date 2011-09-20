#include "Player.hpp"

Player::Player() {
	state = 0;
	x = 0.f;
	y = 0.6f;
	z = 0.f;
	xdir = 0.f;
	xdirdeg = 0.f;
	ydir = 0.f;
	ydirdeg = 0.f;
}

Player::Player(float x, float y, float z, float xdir) : x(x), y(y), z(z), xdir(xdir) {
	state = 0;
	xdirdeg = xdir * RADDEG;
	ydir = 0.f;
	ydirdeg = 0.f;
}

void Player::update(float dt, Map& map, sf::Window& window, bool hasFocus){
	if(state == 0){ // ALIVE
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
	else if(state == 1){
		if(y > 0.2f){
			y -= 0.8f*dt;
		}
		if(ydir > -PI/3.5f){
			ydir -= 2.5f*dt;
			ydirdeg = ydir * RADDEG;
		}
	}
}

int Player::collideDots(std::vector<Pickup>& dots, SndMgr& sndmgr){
	int ret = 0;
	std::vector<Pickup>::iterator it;
	for(it = dots.end(); it >= dots.begin(); it--){
		float dist = pow((float)(x-it->x),2) + pow((float)(z-it->z),2);
		if(dist < 0.15f){
			if(it->type == pickupBig){
				ret = 1; // Set ghosts to scared
				sndmgr.playBigDot();
			}
			else{
				// REMOVED FOR NOW
				//sndmgr.playDot();
			}
			dots.erase(it);
		}
	}
	return ret;
}

void Player::collideGhosts(std::vector<Ghost>& ghosts, SndMgr& sndmgr){
	ghostDist = 1000.f;
	std::vector<Ghost>::iterator it;
	for(it = ghosts.end(); it >= ghosts.begin(); it--) {
		float dist = pow((float)(x-it->x),2) + pow((float)(z-it->z),2);
		if(dist < 0.25f){
			if(it->scaredTime > 0.f){
				it->alive = false;
			}
			else{
				state = 1;
			}
		}
		if(dist < ghostDist){
			ghostDist = dist;
		}
	}
	if(ghostDist < 2.f){
		sndmgr.setNoiseVolume((2.f-ghostDist)*40.f);
	}
	else{
		sndmgr.setNoiseVolume(0.f);
	}
}

void Player::drawEffects(){
	if(state == 1){
		glDisable(GL_TEXTURE_2D);
			float val = 0.2f + 0.6-y;
			glColor4f(1.f,0.f,0.f,val);
			glBegin(GL_QUADS);
				glVertex2f(0,0);
				glVertex2f(SCREEN_WIDTH,0);
				glVertex2f(SCREEN_WIDTH,SCREEN_HEIGHT);
				glVertex2f(0,SCREEN_HEIGHT);
			glEnd();
			glColor4f(1.f,1.f,1.f,1.f);
		glEnable(GL_TEXTURE_2D);
		ghostDist = 1.f;
	}
	if(ghostDist < 2.f){
		// 32-86
		// 74-128
		int stx = rand()%22;
		float tx1 = (float)(32+stx)/128.f;
		float tx2 = (float)(74+stx)/128.f;
		float alpha = (2.f-ghostDist)/10.f;
		glColor4f(1.f,1.f,1.f,alpha);
		glBegin(GL_QUADS);
			glTexCoord2f(tx1,0.5f); 	glVertex2f(0.f,0.f);
			glTexCoord2f(tx2,0.5f); 	glVertex2f(SCREEN_WIDTH,0.f);
			glTexCoord2f(tx2,0.75f); 	glVertex2f(SCREEN_WIDTH,SCREEN_HEIGHT);
			glTexCoord2f(tx1,0.75f); 	glVertex2f(0.f,SCREEN_HEIGHT);
		glEnd();
		glColor4f(1.f,1.f,1.f,1.f);
	}
}
