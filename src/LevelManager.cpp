#include "LevelManager.h"

LevelManager::LevelManager(const std::vector<Level::LevelParams> & levels, Level::LevelVisuals visuals, std::function<void()> onGameEnd)
	:
	m_visuals(visuals),
	c_onGameEnd(onGameEnd),
	m_levels(levels),
	m_currentLevelIt(m_levels.begin()-1)
{
	// load first level
	nextLevel();

	assert(m_currentLevel);
}

void LevelManager::update(double delta)
{
	m_currentLevel->update(delta);
}

void LevelManager::draw()
{
	// draw current level identifications etc.

	// draw level itself
	m_currentLevel->draw();
}

void LevelManager::input(char input)
{
	m_currentLevel->input(input);
}

void LevelManager::onLevelEnd()
{
	nextLevel();
}

void LevelManager::nextLevel()
{
	m_currentLevelIt++;
	if(m_currentLevelIt != m_levels.end())
	{
		std::function<void()> onLevelEnd = std::bind(&LevelManager::onLevelEnd, this);
		m_currentLevel = make_unique<Level>(*m_currentLevelIt, m_visuals, onLevelEnd);
	}
	else
	{
		// callback
		if (c_onGameEnd)
		{
			c_onGameEnd();
		}
		else
		{
			ofLogError("LevelManager") << "Game end callback not set";
		}
	}
}