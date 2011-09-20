#ifndef __SNDMGR_HPP
#define __SNDMGR_HPP

#include <cstdlib>
#include <SFML/Audio.hpp>

class SndMgr {
public:
	SndMgr();
	bool loadSounds();
	void playDot();
	void playBigDot();
	void setNoiseVolume(float vol);
	void setNoisePos(float x, float y, float z);

private:
	sf::Sound sndDot, sndBigDot;
	sf::SoundBuffer dotBfr, bigDotBfr;
	sf::Music musNoise;
	sf::Music musAmbient;
};

#endif
