#include "Game.hpp"

void Game::compileDisplayLists(){
	glNewList(walls,GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0.f,0.f); 			glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.25f,0.f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.25f,0.25f); 		glVertex3f(0.f,0.f,0.f);
		glTexCoord2f(0.f,0.25f); 		glVertex3f(1.f,0.f,0.f);

		glTexCoord2f(0.f,0.f); 			glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.25f,0.f); 		glVertex3f(0.f,1.f,1.f);
		glTexCoord2f(0.25f,0.25f); 		glVertex3f(0.f,0.f,1.f);
		glTexCoord2f(0.f,0.25f); 		glVertex3f(0.f,0.f,0.f);

		glTexCoord2f(0.f,0.f); 			glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.25f,0.f); 		glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.25f,0.25f); 		glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.f,0.25f); 		glVertex3f(1.f,0.f,1.f);

		glTexCoord2f(0.f,0.f); 			glVertex3f(0.f,1.f,1.f);
		glTexCoord2f(0.25f,0.f); 		glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.25f,0.25f); 		glVertex3f(1.f,0.f,1.f);
		glTexCoord2f(0.f,0.25f); 		glVertex3f(0.f,0.f,1.f);
	glEnd();
	glEndList();

	glNewList(floor,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.25f,0.f); 		glVertex3f(0.f,0.f,0.f);
		glTexCoord2f(0.5f,0.f); 		glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.5f,0.25f); 		glVertex3f(1.f,0.f,1.f);
		glTexCoord2f(0.25f,0.25f); 		glVertex3f(0.f,0.f,1.f);
		glEnd();
	glEndList();

	glNewList(lampfloor,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.25f,0.25f); 		glVertex3f(0.f,0.f,0.f);
		glTexCoord2f(0.5f,0.25f); 		glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.5f,0.5f); 		glVertex3f(1.f,0.f,1.f);
		glTexCoord2f(0.25f,0.5f); 		glVertex3f(0.f,0.f,1.f);
		glEnd();
	glEndList();

	glNewList(ceiling,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.5f,0.f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.75f,0.f); 		glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.75f,0.25f); 		glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.5f,0.25f); 		glVertex3f(0.f,1.f,1.f);
		glEnd();
	glEndList();

	glNewList(lampceiling,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.5f,0.25f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(0.75f,0.25f); 		glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(0.75f,0.5f); 		glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.5f,0.5f); 		glVertex3f(0.f,1.f,1.f);
		glEnd();
	glEndList();

	glNewList(lampceilingoff,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.75f,0.25f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(1.f,0.25f); 		glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(1.f,0.5f); 		glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(0.75f,0.5f); 		glVertex3f(0.f,1.f,1.f);
		glEnd();
	glEndList();

	glNewList(smalldot,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f,3.f/8.f); 			glVertex3f(-0.125f,0.25f,0.f);
		glTexCoord2f(1.f/16.f,3.f/8.f); 	glVertex3f(0.125f,0.25f,0.f);
		glTexCoord2f(1.f/16.f,7.f/16.f); 	glVertex3f(0.125f,0.f,0.f);
		glTexCoord2f(0.f,7.f/16.f); 		glVertex3f(-0.125f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(bigdot,GL_COMPILE);
		glBegin(GL_QUADS);
		// TODO
		glEnd();
	glEndList();

	glNewList(redghost,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.25f); 		glVertex3f(-0.5f,1.f,0.f);
		glTexCoord2f(1.f/8.f,0.25f); 	glVertex3f(0.5f,1.f,0.f);
		glTexCoord2f(1.f/8.f,3.f/8.f); 	glVertex3f(0.5f,0.f,0.f);
		glTexCoord2f(0.f, 3.f/8.f); 	glVertex3f(-0.5f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(shadow,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(1.f/8.f, 0.25f); 		glVertex3f(-0.25f,-0.59f,-0.25f);
		glTexCoord2f(2.f/8.f, 0.25f); 		glVertex3f(0.25f,-0.59f,-0.25f);
		glTexCoord2f(2.f/8.f, 3.f/8.f); 	glVertex3f(0.25f,-0.59f,0.25f);
		glTexCoord2f(1.f/8.f, 3.f/8.f); 	glVertex3f(-0.25f,-0.59f,0.25f);
		glEnd();
	glEndList();

	glNewList(portal,GL_COMPILE);
	glBegin(GL_QUADS);
		glTexCoord2f(0.75f,0.f); 		glVertex3f(0.f,1.f,0.f);
		glTexCoord2f(1.0,0.f); 			glVertex3f(0.f,1.f,1.f);
		glTexCoord2f(1.0,0.25f); 		glVertex3f(0.f,0.f,1.f);
		glTexCoord2f(0.75f,0.25f); 		glVertex3f(0.f,0.f,0.f);

		glTexCoord2f(0.75f,0.f); 		glVertex3f(0.33f,1.f,0.f);
		glTexCoord2f(1.0,0.f); 			glVertex3f(0.33f,1.f,1.f);
		glTexCoord2f(1.0,0.25f); 		glVertex3f(0.33f,0.f,1.f);
		glTexCoord2f(0.75f,0.25f); 		glVertex3f(0.33f,0.f,0.f);

		glTexCoord2f(0.75f,0.f); 		glVertex3f(0.66f,1.f,0.f);
		glTexCoord2f(1.0,0.f); 			glVertex3f(0.66f,1.f,1.f);
		glTexCoord2f(1.0,0.25f); 		glVertex3f(0.66f,0.f,1.f);
		glTexCoord2f(0.75f,0.25f); 		glVertex3f(0.66f,0.f,0.f);

		glTexCoord2f(0.75f,0.f); 		glVertex3f(1.f,1.f,1.f);
		glTexCoord2f(1.0,0.f); 			glVertex3f(1.f,1.f,0.f);
		glTexCoord2f(1.0,0.25f); 		glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.75f,0.25f); 		glVertex3f(1.f,0.f,1.f);

		glTexCoord2f(0.25f,0.5f); 		glVertex3f(0.f,0.f,0.f);
		glTexCoord2f(0.5f,0.5f); 		glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.5f,0.75f); 		glVertex3f(1.f,0.f,1.f);
		glTexCoord2f(0.25f,0.75f); 		glVertex3f(0.f,0.f,1.f);
	glEnd();
	glEndList();
}
