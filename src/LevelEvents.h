#pragma once

#include "ofxEntityX.h";

struct TilesDestoyedEvent
{
};

struct LevelEndEvent
{
};

class UseEvent
{
public:
	UseEvent(Entity instigator) : instigator(instigator) {}

	Entity instigator;
};