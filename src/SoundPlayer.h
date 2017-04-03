#pragma once

#include "ofSoundPlayer.h"
#include "GameSounds.h"

class SoundPlayer
{
public:
	SoundPlayer(GameSounds * sounds);

	void playSound(SoundId id);

private:
	GameSounds * m_sounds;
};