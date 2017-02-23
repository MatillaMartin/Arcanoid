#pragma once

#include "ofxEntityX.h"

class CircleCollisionComponent : public Component<CircleCollisionComponent>
{
	CircleCollisionComponent(double radius);

	double radius;
};