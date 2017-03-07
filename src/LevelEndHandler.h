#pragma once

#include "LevelEvents.h"
#include "ofxEntityX.h"

class LevelEndHandler : public Receiver<LevelEndEvent>
{
public:
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

private:
	// callback
	std::function<void()> c_onLevelEnd;
};
