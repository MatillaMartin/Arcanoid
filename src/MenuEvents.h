#pragma once

#include "ofxEntityX.h";

enum MenuItem { MENU_NONE, MENU_PLAY, MENU_CREDITS, MENU_EXIT };

class UseEvent
{
public:
	UseEvent(MenuItem item = MENU_NONE)
		:
		item(item)
	{}

	MenuItem item;
};

class SelectEvent
{
public:
	SelectEvent(Entity entity = Entity())
		:
		entity(entity)
	{}

	Entity entity;
};

struct PlayEvent {};
struct CreditsEvent {};
struct ExitEvent {};