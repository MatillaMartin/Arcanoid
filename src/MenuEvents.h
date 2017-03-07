#pragma once

#include "ofxEntityX.h";

enum MenuItem { NONE, PLAY, CREDITS, EXIT };

class UseEvent
{
public:
	UseEvent(MenuItem item)
		:
		item(item)
	{}

	MenuItem item;
};

class SelectEvent
{
public:
	SelectEvent(Entity entity)
		:
		entity(entity)
	{}

	Entity entity;
};

class PlayEvent
{
};