#pragma once

#include "ofxEntityX.h";

struct DamageEvent
{
	Entity from;
	Entity to;
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