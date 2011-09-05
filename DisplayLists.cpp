#include "Game.hpp"

void Game::compileDisplayLists(){
	walls = glGenLists(4);
	floor = walls+1;
	healthpack = walls+2;
	ammopack = walls+3;

	glNewList(walls,GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0.f,0.f); 			glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.125f,0.f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.125f,0.125f); 	glVertex3f(0.f,0.f,0.f);
		glTexCoord2f(0.f,0.125f); 		glVertex3f(1.f,0.f,0.f);

		glTexCoord2f(0.f,0.f); 			glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.125f,0.f); 		glVertex3f(0.f,1.f,1.f);
		glTexCoord2f(0.125f,0.125f); 	glVertex3f(0.f,0.f,1.f);
		glTexCoord2f(0.f,0.125f); 		glVertex3f(0.f,0.f,0.f);

		glTexCoord2f(0.f,0.f); 			glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.125f,0.f); 		glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.125f,0.125f); 	glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.f,0.125f); 		glVertex3f(1.f,0.f,1.f);

		glTexCoord2f(0.f,0.f); 			glVertex3f(0.f,1.f,1.f);
		glTexCoord2f(0.125f,0.f); 		glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.125f,0.125f); 	glVertex3f(1.f,0.f,1.f);
		glTexCoord2f(0.f,0.125f); 		glVertex3f(0.f,0.f,1.f);
	glEnd();
	glEndList();

	glNewList(floor,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.125f,0.f); 		glVertex3f(0.f,0.f,0.f);
		glTexCoord2f(0.25f,0.f); 		glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.25f,0.125f); 	glVertex3f(1.f,0.f,1.f);
		glTexCoord2f(0.125f,0.125f); 	glVertex3f(0.f,0.f,1.f);

		glTexCoord2f(0.25f,0.f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.375,0.f); 		glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.375,0.125f); 	glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.25f,0.125f); 	glVertex3f(0.f,1.f,1.f);
		glEnd();
	glEndList();

	glNewList(healthpack,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.1875f); 	glVertex3f(-0.25f,0.5f,0.f);
		glTexCoord2f(0.0625f,0.1875f); 	glVertex3f(0.25f,0.5f,0.f);
		glTexCoord2f(0.0625f,0.25f); 	glVertex3f(0.25f,0.f,0.f);
		glTexCoord2f(0.f, 0.25f); 		glVertex3f(-0.25f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(ammopack,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.125f, 0.1875f); 	glVertex3f(-0.25f,0.5f,0.f);
		glTexCoord2f(0.0625f,0.1875f); 	glVertex3f(0.25f,0.5f,0.f);
		glTexCoord2f(0.0625f,0.25f); 	glVertex3f(0.25f,0.f,0.f);
		glTexCoord2f(0.125f, 0.25f); 	glVertex3f(-0.25f,0.f,0.f);
		glEnd();
	glEndList();
}
