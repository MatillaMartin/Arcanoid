#pragma once

#include "ofSoundPlayer.h"
#include "Sounds.h"

class GameSounds
{
public:
	typedef std::map<SoundId, ofSoundPlayer> SoundMap;

	GameSounds();

	ofSoundPlayer & getSound(SoundId sound);

	private:
		SoundMap m_sounds;
		ofSoundPlayer m_noSound;
};