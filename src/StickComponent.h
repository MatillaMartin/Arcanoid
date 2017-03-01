#pragma once

#include "ofxEntityX.h"

class StickComponent : public Component<StickComponent >
{
public:
	StickComponent(float stickTime);

	float stickTime;
};