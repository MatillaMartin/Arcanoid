#include "GameSounds.h"

GameSounds::GameSounds()
{
	m_noSound.unload();
	m_sounds[SoundId::NONE].unload();
	m_sounds[SoundId::BALL_0].load("audio/ball_0.wav");
	m_sounds[SoundId::BALL_1].load("audio/ball_1.wav");
	m_sounds[SoundId::BALL_2].load("audio/ball_2.wav");
	m_sounds[SoundId::BALL_3].load("audio/ball_3.wav");
	m_sounds[SoundId::SELECT].load("audio/select.wav");
}

ofSoundPlayer & GameSounds::getSound(SoundId sound)
{
	if (m_sounds.find(sound) != m_sounds.end())
	{
		return m_sounds.at(sound);
	}
	return m_noSound;
}
