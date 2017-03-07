#pragma once

#include "ofxEntityX.h"
#include "PlayEventHandler.h"

class MainMenu : public ofxEntityX
{
public:
	MainMenu(std::function<void()> onPlay);
	void update(float delta);
	void draw();

private:
	void setupEntityX();
	void setupMenu();

	PlayEventHandler m_playEventHandler;
};