#pragma once
#include "ofxEntityX.h"

class BallVisualComponent : Component<BallVisualComponent>
{
public:
	BallVisualComponent(double radius);

	virtual void onHit() = 0;

	double radius;
};