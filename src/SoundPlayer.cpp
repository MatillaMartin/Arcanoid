#include "SoundPlayer.h"

SoundPlayer::SoundPlayer(GameSounds * sounds)
	:
	m_sounds(sounds)
{
}

void SoundPlayer::playSound(SoundId id)
{
	m_sounds->getSound(id).play();
}
