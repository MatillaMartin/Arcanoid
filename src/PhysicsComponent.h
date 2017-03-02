#pragma once
#include "ofxEntityX.h"
#include "ofMath.h"

class PhysicsComponent : public Component<PhysicsComponent>
{
public:
	PhysicsComponent(const glm::vec2 & position = glm::vec2());

	glm::vec2 position;
	glm::vec2 velocity;
};