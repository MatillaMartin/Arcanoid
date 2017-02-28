#pragma once

#include "Events.h"
#include "ofxEntityX.h"

class LevelEndHandler : public Receiver<LevelEndEvent>
{
	LevelEndHandler(std::function<void()> onLevelEnd)
		:
		c_onLevelEnd(onLevelEnd)
	{}

	void receive(const LevelEndEvent &e) 
	{
		if (c_onLevelEnd)
		{
			c_onLevelEnd();
		}
		else
		{
			ofLogError("LevelEndHandler") << "Level end callback not set";
		}
	}

	// callback
	std::function<void()> c_onLevelEnd;
};
