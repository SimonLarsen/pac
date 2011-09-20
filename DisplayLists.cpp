#include "Game.hpp"

void Game::compileDisplayLists(){
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
		glTexCoord2f(0.f,1.f/4.f); 			glVertex3f(-0.125f,0.25f,0.f);
		glTexCoord2f(1.f/16.f,1.f/4.f); 	glVertex3f(0.125f,0.25f,0.f);
		glTexCoord2f(1.f/16.f,5.f/16.f); 	glVertex3f(0.125f,0.f,0.f);
		glTexCoord2f(0.f,5.f/16.f); 		glVertex3f(-0.125f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(bigdot,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(1.f/8.f,3.f/8.f); 		glVertex3f(-0.25f,0.5f,0.f);
		glTexCoord2f(1.f/4.f,3.f/8.f); 		glVertex3f(0.25f,0.5f,0.f);
		glTexCoord2f(1.f/4.f,1.f/2.f); 		glVertex3f(0.25f,0.f,0.f);
		glTexCoord2f(1.f/8.f,1.f/2.f); 		glVertex3f(-0.25f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(redghost,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 7.f/8.f); 		glVertex3f(-0.45f,0.9f,0.f);
		glTexCoord2f(1.f/8.f,7.f/8.f); 		glVertex3f(0.45f,0.9f,0.f);
		glTexCoord2f(1.f/8.f,1.f); 			glVertex3f(0.45f,0.f,0.f);
		glTexCoord2f(0.f, 1.f); 			glVertex3f(-0.45f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(blueghost,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(1.f/8.f, 7.f/8.f); 	glVertex3f(-0.45f,0.9f,0.f);
		glTexCoord2f(2.f/8.f,7.f/8.f); 		glVertex3f(0.45f,0.9f,0.f);
		glTexCoord2f(2.f/8.f,1.f); 			glVertex3f(0.45f,0.f,0.f);
		glTexCoord2f(1.f/8.f, 1.f); 		glVertex3f(-0.45f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(pinkghost,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(2.f/8.f, 7.f/8.f); 	glVertex3f(-0.45f,0.9f,0.f);
		glTexCoord2f(3.f/8.f,7.f/8.f); 		glVertex3f(0.45f,0.9f,0.f);
		glTexCoord2f(3.f/8.f,1.f); 			glVertex3f(0.45f,0.f,0.f);
		glTexCoord2f(2.f/8.f, 1.f); 		glVertex3f(-0.45f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(yellowghost,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(3.f/8.f, 7.f/8.f); 	glVertex3f(-0.45f,0.9f,0.f);
		glTexCoord2f(4.f/8.f,7.f/8.f); 		glVertex3f(0.45f,0.9f,0.f);
		glTexCoord2f(4.f/8.f,1.f); 			glVertex3f(0.45f,0.f,0.f);
		glTexCoord2f(3.f/8.f, 1.f); 		glVertex3f(-0.45f,0.f,0.f);
		glEnd();
	glEndList();

	glNewList(scaredghost,GL_COMPILE);
		glBegin(GL_QUADS);
		glTexCoord2f(4.f/8.f, 7.f/8.f); 	glVertex3f(-0.45f,0.9f,0.f);
		glTexCoord2f(5.f/8.f,7.f/8.f); 		glVertex3f(0.45f,0.9f,0.f);
		glTexCoord2f(5.f/8.f,1.f); 			glVertex3f(0.45f,0.f,0.f);
		glTexCoord2f(4.f/8.f, 1.f); 		glVertex3f(-0.45f,0.f,0.f);
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

		glTexCoord2f(0.f,0.5f); 		glVertex3f(0.f,0.f,0.f);
		glTexCoord2f(0.25f,0.5f); 		glVertex3f(1.f,0.f,0.f);
		glTexCoord2f(0.25f,0.75f); 		glVertex3f(1.f,0.f,1.f);
		glTexCoord2f(0.f,0.75f); 		glVertex3f(0.f,0.f,1.f);
	glEnd();
	glEndList();
}
