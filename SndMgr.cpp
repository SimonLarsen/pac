#include "SndMgr.hpp"

SndMgr::SndMgr(){
}

bool SndMgr::loadSounds(){
	if(dotBfr.LoadFromFile("./res/dot.wav") == false)
		return false;
	sndDot.SetBuffer(dotBfr);

	if(bigDotBfr.LoadFromFile("./res/bigdot.wav") == false)
		return false;
	sndBigDot.SetBuffer(bigDotBfr);

	if(musNoise.OpenFromFile("./res/noise.ogg") == false)
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

void SndMgr::playDot(){
	sndDot.Play();
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
