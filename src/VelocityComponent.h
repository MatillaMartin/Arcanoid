#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"

class VelocityComponent
{
public:
	VelocityComponent(const glm::vec2 & velocity);

	glm::vec2 velocity;
};