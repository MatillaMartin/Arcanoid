#include "GameSounds.h"

GameSounds::GameSounds()
{
	m_noSound = make_unique<ofSoundPlayer>();
	m_sounds[SoundId::NONE] = make_unique<ofSoundPlayer>();
	m_sounds[SoundId::BALL_0] = make_unique<ofSoundPlayer>();
	m_sounds[SoundId::BALL_1] = make_unique<ofSoundPlayer>();
	m_sounds[SoundId::BALL_2] = make_unique<ofSoundPlayer>();
	m_sounds[SoundId::BALL_3] = make_unique<ofSoundPlayer>();
	m_sounds[SoundId::SELECT] = make_unique<ofSoundPlayer>();

	m_sounds[SoundId::BALL_0]->load("audio/ball_0.wav");
	m_sounds[SoundId::BALL_1]->load("audio/ball_1.wav");
	m_sounds[SoundId::BALL_2]->load("audio/ball_2.wav");
	m_sounds[SoundId::BALL_3]->load("audio/ball_3.wav");
	m_sounds[SoundId::SELECT]->load("audio/select.wav");
}

ofSoundPlayer * GameSounds::getSound(SoundId sound)
{
	if (m_sounds.find(sound) != m_sounds.end())
	{
		return m_sounds.at(sound).get();
	}
	return m_noSound.get();
}
