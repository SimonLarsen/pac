#include "Particle.hpp"

Particle::Particle(float x, float y, float z, ParticleType type) : x(x), y(y), z(z), type(type) {
	frame = 0.f;
	alive = true;
}

void Particle::update(float dt){
	if(type == particleKillGhost){
		frame += 8.f*dt;
	}
}

void Particle::draw(float dirdeg){
	if(type == particleKillGhost){
		glPushMatrix();
		glTranslatef(x,y,z);
		glRotatef(-dirdeg,0,1,0);

		float tex1,tex2;
		if(frame < 7.f){
			tex1 = floor(frame)/8.f;
			tex2 = (floor(frame)+1)/8.f;
		}
		else{
			tex1 = 7.f/8.f;
			tex2 = 1.f;
		}
		glBegin(GL_QUADS);	
			glTexCoord2f(tex1, 0.75f); 		glVertex3f(-0.45f,0.9f,0.f);
			glTexCoord2f(tex2, 0.75f); 		glVertex3f(0.45f,0.9f,0.f);
			glTexCoord2f(tex2, 0.875f); 	glVertex3f(0.45f,0.f,0.f);
			glTexCoord2f(tex1, 0.875); 		glVertex3f(-0.45f,0.f,0.f);
		glEnd();

		glRotatef(dirdeg,0,1,0);
		if(frame >= 5.f){
			if(frame < 20.f){
				float scale = 1.f - (20.f-floor(frame))/16.f;
				glScalef(scale,1,scale);
			}
			glBegin(GL_QUADS);	
				glTexCoord2f(0.f,3.f/8.f); 		glVertex3f(-0.5f,0.01f,-0.5f);
				glTexCoord2f(1.f/8.f,3.f/8.f); 	glVertex3f(0.5f,0.01f,-0.5f);
				glTexCoord2f(1.f/8.f,0.5f); 	glVertex3f(0.5f,0.01f,0.5f);
				glTexCoord2f(0.f,0.5f); 		glVertex3f(-0.5f,0.01f,0.5f);
			glEnd();
			glPopMatrix();
		}
	}
}
