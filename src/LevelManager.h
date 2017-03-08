#pragma once

#include "Screen.h"
#include "Level.h"

class LevelManager : public Screen
{
public:
	LevelManager(const std::vector<Level::Params> & levels, Level::Visuals levelVisuals, std::function<void()> onGameEnd);

	void update(double delta) override;
	void draw(Renderer * renderer) override;
	void input(char input) override;

	void load(unsigned int level);

private:
	std::vector<Level::Params> m_levels;
	Level::Visuals m_visuals;

	unique_ptr<Level> m_currentLevel;

	void onLevelEnd();
	void nextLevel();
	void startLevel();


	std::function<void()> c_onGameEnd;

	std::vector<Level::Params>::iterator m_currentLevelIt;
};