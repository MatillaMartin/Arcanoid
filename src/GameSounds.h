#pragma once

#include "ofSoundPlayer.h"
#include "Sounds.h"

class GameSounds
{
public:
	typedef std::map<SoundId, std::unique_ptr<ofSoundPlayer>> SoundMap;

	GameSounds();

	ofSoundPlayer * getSound(SoundId sound);

	private:
		SoundMap m_sounds;
		std::unique_ptr<ofSoundPlayer> m_noSound;
};