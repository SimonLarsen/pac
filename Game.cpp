#include "Game.hpp"

Game::Game(){
	running = false;
}

void Game::loop(){
	running = true;

	pl.x = 4.5f;
	pl.y = 0.6f;
	pl.z = 4.5f;

	while(running){
		float time = clock.GetElapsedTime()/1000.f;
		clock.Reset();
		while(app.PollEvent(event)){
			if(event.Type == sf::Event::Closed){
				running = false;
			}
		}

		pl.update(time, map);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glRotatef(pl.dirdeg,0,1,0);
		glTranslatef(-pl.x,-pl.y,-pl.z);

		glPushMatrix();

		glDisable(GL_BLEND);

		// Draw walls, floors
		for(int ix = 0; ix < map.w; ++ix) {
			for(int iy = 0; iy < map.h; ++iy) {
				if(map.data[iy*map.w+ix] == 1){
					glCallList(walls);
				}
				else if(map.data[iy*map.w+ix] == 0){
					glCallList(floor);
					//glCallList(ceiling);
				}
				glTranslatef(1,0,0);
			}
			glTranslatef(-map.w,0,1);
		}
		glPopMatrix();

		glEnable(GL_BLEND);

		// Draw dots
		for(int i = 0; i < dots.size(); ++i) {
			glPushMatrix();
			glTranslatef(dots.at(i).x,0,dots.at(i).z);
			glRotatef(-pl.dirdeg,0,1,0);
			glCallList(smalldot);
			glPopMatrix();
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
	glAlphaFunc(GL_GREATER,0.5f);
	glEnable(GL_ALPHA_TEST);

	return true;
}

bool Game::loadResources(){
	if(Game::tiles.LoadFromFile("res/tiles.png") == false){
		return false;
	}
	Game::tiles.SetSmooth(false);
	Game::tiles.Bind();

	compileDisplayLists();

	if(map.readFromFile("res/map.dat") == false){
		return false;
	}

	dots.push_back(Pickup(1.5f,1.5f,pickupSmall));
	dots.push_back(Pickup(2.5f,1.5f,pickupSmall));
	dots.push_back(Pickup(3.5f,1.5f,pickupSmall));
	dots.push_back(Pickup(4.5f,1.5f,pickupSmall));
	dots.push_back(Pickup(5.5f,1.5f,pickupSmall));
	dots.push_back(Pickup(6.5f,1.5f,pickupSmall));
	dots.push_back(Pickup(7.5f,1.5f,pickupSmall));
	dots.push_back(Pickup(8.5f,1.5f,pickupSmall));

	return true;
}

int main(int argc, char** argv){
	Game game;
	return game.execute();
}
