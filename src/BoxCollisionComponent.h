#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"

class BoxCollisionComponent : Component<BoxCollisionComponent>
{
public:
	BoxCollisionComponent(const glm::vec2 & size);

	glm::vec2 size;
};