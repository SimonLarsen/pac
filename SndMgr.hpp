#ifndef __SNDMGR_HPP
#define __SNDMGR_HPP

#include <cstdlib>
#include <SFML/Audio.hpp>
#include <cmath>

class SndMgr {
public:
	SndMgr();
	bool loadSounds();
	void playDot();
	void playBigDot();
	void playGhostDeath();
	void playDeath();
	void playStep();
	void setNoiseVolume(float vol);
	void setNoisePos(float x, float y, float z);

private:
	sf::Sound sndDot, sndBigDot, sndGhostDeath, sndDeath;
	sf::Sound sndStep1, sndStep2;

	sf::SoundBuffer dotBfr, bigDotBfr, ghostDeathBfr, deathBfr;
	sf::SoundBuffer step1Bfr, step2Bfr;

	sf::Music musNoise;
	sf::Music musAmbient;
};

#endif
