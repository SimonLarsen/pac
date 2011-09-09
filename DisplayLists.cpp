#include "Game.hpp"

void Game::compileDisplayLists(){
	walls = glGenLists(6);
	floor = walls+1;
	ceiling = walls+2;
	smalldot = walls+3;
	bigdot = walls+4;
	redghost = walls+5;

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
		glEnd();
	glEndList();

	glNewList(ceiling,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.25f,0.f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.375,0.f); 		glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.375,0.125f); 	glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.25f,0.125f); 	glVertex3f(0.f,1.f,1.f);
		glEnd();
	glEndList();

	glNewList(smalldot,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f,48.f/256.f); 		glVertex3f(-0.125f,0.25f,0.f);
		glTexCoord2f(8.f/256.f,48.f/256.f); glVertex3f(0.125f,0.25f,0.f);
		glTexCoord2f(8.f/256.f,56.f/256.f); glVertex3f(0.125f,0.f,0.f);
		glTexCoord2f(0.f,56.f/256.f); 		glVertex3f(-0.125f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(bigdot,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.125f, 0.1875f); 	glVertex3f(-0.25f,0.5f,0.f);
		glTexCoord2f(0.0625f,0.1875f); 	glVertex3f(0.25f,0.5f,0.f);
		glTexCoord2f(0.0625f,0.25f); 	glVertex3f(0.25f,0.f,0.f);
		glTexCoord2f(0.125f, 0.25f); 	glVertex3f(-0.25f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(redghost,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.125f); 	glVertex3f(-0.5f,1.f,0.f);
		glTexCoord2f(0.0625f,0.125f); 	glVertex3f(0.5f,1.f,0.f);
		glTexCoord2f(0.0625f,0.1875f); 	glVertex3f(0.5f,0.f,0.f);
		glTexCoord2f(0.f, 0.1875f); 	glVertex3f(-0.5f,0.f,0.f);
		glEnd();
	glEndList();
}
