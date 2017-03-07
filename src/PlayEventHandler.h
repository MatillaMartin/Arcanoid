#pragma once

#include "ofxEntityX.h"
#include "ofLog.h"
#include "MenuEvents.h"

class PlayEventHandler : public Receiver<PlayEventHandler>
{
public:
	PlayEventHandler(std::function<void()> onPlay)
		:
		c_onPlay(onPlay)
	{}

	void receive(const PlayEvent &e)
	{
		if (c_onPlay)
		{
			c_onPlay();
		}
		else
		{
			ofLogError("PlayEventHandler") << "PlayEvent callback not set";
		}
	}

private:
	// callback
	std::function<void()> c_onPlay;
};
