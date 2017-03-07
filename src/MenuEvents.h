#pragma once

#include "ofxEntityX.h";

enum MenuItem { MENU_NONE, MENU_PLAY, MENU_CREDITS, MENU_EXIT };

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