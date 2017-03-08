#pragma once

#include "ofxEntityX.h"
#include "ofLog.h"

template<typename T>
class EventHandler : public Receiver<EventHandler<T>>
{
public:
	EventHandler(std::function<void()> onEvent)
	:
	c_onEvent(onEvent)
	{}

	void receive(const T &e)
	{
		if (c_onEvent)
		{
			c_onEvent();
		}
		else
		{
			ofLogError("EventHandler") << "Callback not set";
		}
	}

private:
	// callback
	std::function<void()> c_onEvent;
};