#pragma once

#include "ofxEntityX.h"

class BoxCollisionComponent : Component<BoxCollisionComponent>
{
public:
	BoxCollisionComponent(const glm::vec2 & size);

	glm::vec2 size;
};