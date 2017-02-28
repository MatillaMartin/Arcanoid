#pragma once

#include "Level.h"

class LevelManager
{
public:
	LevelManager(const std::vector<Level::LevelParams> & levels, Level::LevelVisuals levelVisuals, std::function<void()> onGameEnd);

	void update(double delta);
	void draw();

private:
	std::vector<Level::LevelParams> m_levels;
	Level::LevelVisuals m_visuals;

	unique_ptr<Level> m_currentLevel;

	void onLevelEnd();
	void nextLevel();

	std::function<void()> c_onGameEnd;

	std::vector<Level::LevelParams>::iterator m_currentLevelIt;
};