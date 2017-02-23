#pragma once

#include "ofxEntityX.h"

class BoxCollisionComponent : Component<BoxCollisionComponent>
{
public:
	BoxCollisionComponent(double width, double height);

private:
	double width;
	double height;
};