#pragma once

#include "ofxEntityX.h"

class StickComponent : public Component<StickComponent>
{
public:
	StickComponent(Entity who, float maxStickTime, float releaseSpeed);

	Entity who;
	float maxStickTime;
	float currentStickTime;
	float releaseSpeed;
};