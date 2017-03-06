#pragma once
#include "ofxEntityX.h"
#include "ofMath.h"

class PhysicsComponent : public Component<PhysicsComponent>
{
public:

	PhysicsComponent(	const glm::vec2 & position = glm::vec2(),
						const glm::vec2 & size = glm::vec2(),
						const glm::vec2 & velocity = glm::vec2(),
						const glm::vec2 & acceleration = glm::vec2(),
						const glm::vec2 & frictionCoeff = glm::vec2()
	);

	glm::vec2 position;
	glm::vec2 size;

	glm::vec2 velocity;
	glm::vec2 acceleration;
	glm::vec2 frictionCoeff;
};