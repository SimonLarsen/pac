#include "Game.hpp"

Game::Game(){
	running = false;
	lampOn = true;
	lampTime = 0.f;
	paused = false;
}

void Game::loop(){
	running = true;

	ghosts.push_back(Ghost(9,9,0));
	ghosts.push_back(Ghost(8,10,1));
	ghosts.push_back(Ghost(9,10,2));
	ghosts.push_back(Ghost(10,10,3));

	sf::Mouse::SetPosition(sf::Vector2i(SCREEN_WIDTH/2,SCREEN_HEIGHT/2),app);

	std::vector<Ghost>::iterator it;
	while(running){
		float time = clock.GetElapsedTime()/1000.f;
		clock.Reset();
		while(app.PollEvent(event)){
			if(event.Type == sf::Event::Closed){
				running = false;
			}
			else if(event.Type == sf::Event::KeyPressed){
				if(event.Key.Code == sf::Keyboard::P){
					paused = !paused;
				}
			}
			else if(event.Type == sf::Event::GainedFocus){
				hasFocus = true;
			}
			else if(event.Type == sf::Event::LostFocus){
				hasFocus = false;
			}
		}

		if(!paused){
			// Update player
			pl.update(time, map, app, hasFocus);
			if(pl.collideDots(dots) == 1){
				for(it = ghosts.begin(); it < ghosts.end(); ++it){
					it->setScared();	
				}
			}
			// Update ghosts
			for(it = ghosts.begin(); it < ghosts.end(); ++it) {
				it->update(time,map);	
			}

			// Update lamp blinking
			if(lampTime < 0){
				if(lampOn)
					lampTime = (float)(rand() % 10 + 5)/100.f;
				else
					lampTime = (float)(rand() % 50 + 10)/100.f;
				lampOn = !lampOn;
			}
			lampTime -= time;
		}

		// Clear screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// Rotate view
		glRotatef(pl.ydirdeg,1,0,0);
		glRotatef(pl.xdirdeg,0,1,0);

		// Draw shadow
		glCallList(shadow);

		// Translate according to player coords
		glTranslatef(-pl.x,-pl.y,-pl.z);

		glPushMatrix();

		// Draw walls, floors
		for(int iy = 0; iy < map.h; ++iy) {
			for(int ix = 0; ix < map.w; ++ix) {
				char tile = map.data[iy*map.w+ix];
				switch(tile){
					case 0:
						glCallList(floor);
						glCallList(ceiling);
						break;
					case 1:
						glCallList(walls);
						break;
					case 2:
						if(lampOn){
							glCallList(lampfloor);
							glCallList(lampceiling);
						}
						else{
							glCallList(floor);
							glCallList(lampceilingoff);
						}
						break;
					case 3:
						glCallList(portal);
						break;
				}
				glTranslatef(1,0,0);
			}
			glTranslatef(-map.w,0,1);
		}
		glPopMatrix();

		// Draw dots
		for(int i = 0; i < dots.size(); ++i) {
			dots.at(i).draw(pl.xdirdeg);
		}
		// Draw ghosts
		for(it = ghosts.begin(); it < ghosts.end(); ++it){
			it->draw(pl.xdirdeg);
		}

		app.Display();
	}
}

int Game::execute(){
	if(init() == false){
		return -1;
	}
	loop();
	return 0;
}

bool Game::init(){
	app.Create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP),"FPS",sf::Style::Close);
	if(app.IsOpened() == false){
		return false;
	}
	app.ShowMouseCursor(false);

	walls = glGenLists(6);
	floor = walls+1;
	lampfloor = floor+1;
	ceiling = lampfloor+1;
	lampceiling = ceiling+1;
	lampceilingoff = lampceiling+1;

	smalldot = glGenLists(4);
	bigdot = smalldot+1;
	shadow = bigdot+1;
	portal = shadow+1;

	redghost = glGenLists(5);
	blueghost = redghost+1;
	pinkghost = blueghost+1;
	yellowghost = pinkghost+1;
	scaredghost = yellowghost+1;

	Pickup::init(smalldot);
	Ghost::init(redghost);

	if(loadResources() == false){
		return false;
	}

	srand((int)(clock.GetElapsedTime()*1000.f));

	// Init projection matrix
	glViewport(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.f,(GLfloat)SCREEN_WIDTH/(GLfloat)SCREEN_HEIGHT,0.1f,100.f);
	// Init model view matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Background color
	glClearColor(0.f,0.f,0.f,0.f);
	// Depth buffer
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_TEXTURE_2D);
	// Blend function
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_BLEND);
	// Only allow pixels with alpha > 0.9 to be drawn
	glAlphaFunc(GL_GREATER,0.9f);
	glEnable(GL_ALPHA_TEST);
	// Fog stuff
	GLfloat fogColor[] = {0.f,0.f,0.f,1.f};
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.65f);
	glHint(GL_FOG_HINT, GL_FASTEST);
	glFogf(GL_FOG_START, 0.5f);
	glFogf(GL_FOG_END, 6.0f);
	glEnable(GL_FOG);

	return true;
}

bool Game::loadResources(){
	if(tiles.LoadFromFile("res/tiles.png") == false){
		return false;
	}
	Game::tiles.SetSmooth(false);
	Game::tiles.Bind();

	compileDisplayLists();

	//if(map.readFromFile("res/map.dat") == false){
	if(map.readFromImage("res/levels/1.png",dots) == false){
		return false;
	}
	pl.x = map.startx;
	pl.z = map.startz;

	return true;
}

int main(int argc, char** argv){
	Game game;
	return game.execute();
}
