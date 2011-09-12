#include "Game.hpp"

Game::Game(){
	running = false;
}

void Game::loop(){
	running = true;

	pl.y = 0.6f;

	Ghost ghost(13.5f,20.5f);

	while(running){
		float time = clock.GetElapsedTime()/1000.f;
		elapsedtime += time;
		clock.Reset();
		while(app.PollEvent(event)){
			if(event.Type == sf::Event::Closed){
				running = false;
			}
			else if(event.Type == sf::Event::GainedFocus){
				hasFocus = true;
			}
			else if(event.Type == sf::Event::LostFocus){
				hasFocus = false;
			}
		}

		pl.update(time, map, app, hasFocus);
		pl.collideDots(dots);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glRotatef(pl.dirdeg,0,1,0);
		glTranslatef(-pl.x,-pl.y,-pl.z);

		glPushMatrix();

		glDisable(GL_BLEND);

		// Draw walls, floors
		for(int iy = 0; iy < map.h; ++iy) {
			for(int ix = 0; ix < map.w; ++ix) {
				if(map.data[iy*map.w+ix] == 1){
					glCallList(walls);
				}
				else if(map.data[iy*map.w+ix] == 0){
					glCallList(floor);
				}
				glTranslatef(1,0,0);
			}
			glTranslatef(-map.w,0,1);
		}
		glPopMatrix();

		glEnable(GL_BLEND);

		// Draw dots
		for(int i = 0; i < dots.size(); ++i) {
			dots.at(i).draw(pl.dirdeg);
		}
		ghost.draw(pl.dirdeg);

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

	walls = glGenLists(6);
	floor = walls+1;
	ceiling = walls+2;
	smalldot = walls+3;
	bigdot = walls+4;
	redghost = walls+5;
	Pickup::init(smalldot);
	Ghost::init(redghost);

	if(loadResources() == false){
		return false;
	}

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
	// Only allow pixels with alpha > 0.5 to be drawn
	glAlphaFunc(GL_GREATER,0.9f);
	glEnable(GL_ALPHA_TEST);
	// Fog stuff
	GLfloat fogColor[] = {0.f,0.f,0.f,1.f};
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glFogi(GL_FOG_MODE, GL_EXP2);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.65f);
	glHint(GL_FOG_HINT, GL_FASTEST);
	glFogf(GL_FOG_START, 1.0f);
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
