#include "SndMgr.hpp"

SndMgr::SndMgr(){
}

bool SndMgr::loadSounds(){
	if(bigDotBfr.LoadFromFile("./res/bigdot.wav") == false)
		return false;
	sndBigDot.SetBuffer(bigDotBfr);
	sndBigDot.SetVolume(50.f);

	if(ghostDeathBfr.LoadFromFile("./res/ghostdeath.wav") == false)
		return false;
	sndGhostDeath.SetBuffer(ghostDeathBfr);

	if(deathBfr.LoadFromFile("./res/death.wav") == false)
		return false;
	sndDeath.SetBuffer(deathBfr);

	if(step1Bfr.LoadFromFile("./res/step1.wav") == false)
			return false;
	sndStep1.SetBuffer(step1Bfr);

	if(step2Bfr.LoadFromFile("./res/step2.wav") == false)
			return false;
	sndStep2.SetBuffer(step1Bfr);

	if(musNoise.OpenFromFile("./res/noise2.ogg") == false)
		return false;
	musNoise.SetVolume(0.f);
	musNoise.SetLoop(true);
	musNoise.Play();

	if(musAmbient.OpenFromFile("./res/ambient.ogg") == false)
		return false;
	musAmbient.SetLoop(true);
	musAmbient.Play();

	return true;
}

void SndMgr::playBigDot(){
	sndBigDot.Play();
}

void SndMgr::setNoiseVolume(float vol){
	musNoise.SetVolume(vol);
}

void SndMgr::setNoisePos(float x, float y, float z){
	musNoise.SetPosition(x,y,z);
}

void SndMgr::playGhostDeath(){
	sndGhostDeath.Play();
}

void SndMgr::playDeath(){
	sndDeath.Play();
}

void SndMgr::playStep(){
	if(rand() % 2 == 0)
		sndStep1.Play();
	else
		sndStep2.Play();
}
