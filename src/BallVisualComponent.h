#pragma once
#include "ofxEntityX.h"

class BallVisualComponent : Component<BallVisualComponent>
{
public:
	BallVisualComponent(float radius);

	float radius;
};