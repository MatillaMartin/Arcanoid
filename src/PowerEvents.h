#pragma once

#include "ofxEntityX.h"
#include "ofLog.h"

enum class PowerType { NONE, STICK, SHOOT };

struct UseStickEvent
{
	UseStickEvent(Entity stickable, Entity to, float releaseSpeed) : stickable(stickable), to(to), releaseSpeed(releaseSpeed) {}
	Entity stickable;
	Entity to;
	float releaseSpeed;
};

struct StickCollision
{
	StickCollision(Entity stickable, Entity to) : stickable(stickable), to(to) {}
	Entity stickable;
	Entity to;
};