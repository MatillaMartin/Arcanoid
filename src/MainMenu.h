#pragma once

#include "ofxEntityX.h"
#include "PlayEventHandler.h"

class MainMenu : public ofxEntityX
{
public:
	MainMenu(std::function<void()> onPlay);
	void update();
	void draw();

private:
	void setupEntityX();

	PlayEventHandler m_playEventHandler;
};