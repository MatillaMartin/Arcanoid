#pragma once

#include "ofxEntityX.h";

enum class MenuItem { MENU_NONE, MENU_PLAY, MENU_CREDITS, MENU_EXIT };

class UseMenuEvent
{
public:
	UseMenuEvent(MenuItem item = MenuItem::MENU_NONE)
		:
		item(item)
	{}

	MenuItem item;
};

class SelectMenuEvent
{
public:
	SelectMenuEvent(Entity entity = Entity())
		:
		entity(entity)
	{}

	Entity entity;
};

struct PlayEvent {};
struct CreditsEvent {};
struct ExitEvent {};