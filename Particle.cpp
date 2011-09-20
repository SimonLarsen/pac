#include "Particle.hpp"

Particle::Particle(float x, float y, float z, ParticleType type) : x(x), y(y), z(z), type(type) {
	frame = 0.f;
	alive = true;
}

void Particle::update(float dt){
	if(type == particleKillGhost){
		frame += 8.f*dt;
		if(frame > 10.f){
			alive = false;
		}
	}
}

void Particle::draw(float dirdeg){
	if(type == particleKillGhost){
		float tex1,tex2;
		if(frame < 7.f){
			tex1 = floor(frame)/8.f;
			tex2 = (floor(frame)+1)/8.f;
		}
		else{
			tex1 = 7.f/8.f;
			tex2 = 1.f;
		}
		glPushMatrix();
		glTranslatef(x,y,z);
		glRotatef(-dirdeg,0,1,0);
		glBegin(GL_QUADS);	
			glTexCoord2f(tex1, 0.75f); 		glVertex3f(-0.45f,0.9f,0.f);
			glTexCoord2f(tex2, 0.75f); 		glVertex3f(0.45f,0.9f,0.f);
			glTexCoord2f(tex2, 0.875f); 	glVertex3f(0.45f,0.f,0.f);
			glTexCoord2f(tex1, 0.875); 		glVertex3f(-0.45f,0.f,0.f);
		glEnd();
		glPopMatrix();
	}
}
