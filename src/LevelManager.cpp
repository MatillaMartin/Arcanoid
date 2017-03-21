#include "LevelManager.h"

LevelManager::LevelManager(const std::vector<Level::Params> & levels, Level::Visuals visuals, std::function<void()> onGameEnd)
	:
	m_visuals(visuals),
	c_onGameEnd(onGameEnd),
	m_levels(levels),
	m_currentLevelIt(m_levels.begin())
{
	assert(!m_levels.empty());
}

void LevelManager::update(double delta)
{
	assert(m_currentLevel);
	m_currentLevel->update(delta);
}

void LevelManager::draw(Renderer * renderer)
{
	assert(m_currentLevel);

	// draw current level identifications etc.
	renderer->drawSprite(glm::vec2(0), glm::vec2(1), TextureId::LEVEL_0);

	// draw level itself
	m_currentLevel->draw(renderer);
}

void LevelManager::input(char input)
{
	assert(m_currentLevel);
	m_currentLevel->input(input);
}

void LevelManager::onLevelEnd()
{
	nextLevel();
}

void LevelManager::load(unsigned int level)
{
	if (level < m_levels.size())
	{
		m_currentLevelIt = m_levels.begin() + level;
		startLevel();
	}
	else
	{
		ofLogError("LevelManager") << "Level " << level << " does not exist";
	}
}

void LevelManager::nextLevel()
{
	m_currentLevelIt++;
	startLevel();
}

void LevelManager::startLevel()
{
	if (m_currentLevelIt != m_levels.end())
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