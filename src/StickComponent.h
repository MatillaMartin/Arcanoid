#pragma once

#include "ofxEntityX.h"

class StickComponent : public Component<StickComponent>
{
public:
	class StickableComponent : public Component<StickableComponent> {};


	StickComponent(Entity stickable, float maxStickTime, float releaseSpeed);

	Entity stickable;
	float maxStickTime;
	float currentStickTime;
	float releaseSpeed;
};