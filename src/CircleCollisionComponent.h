#pragma once

#include "ofxEntityX.h"

class CircleCollisionComponent : public Component<CircleCollisionComponent>
{
public:
	CircleCollisionComponent(float radius);

	float radius;
};