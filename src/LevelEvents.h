#pragma once

#include "ofxEntityX.h";

struct TilesDestoyedEvent
{
};

struct LevelEndEvent
{
};

class PaddleUseEvent
{
public:
	PaddleUseEvent(Entity instigator) : instigator(instigator) {}

	Entity instigator;
};