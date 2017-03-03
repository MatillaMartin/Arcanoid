#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(	const glm::vec2 & position, const glm::vec2 & velocity, const glm::vec2 & size)
	:
	position(position),
	velocity(velocity),
	size(size)
{}