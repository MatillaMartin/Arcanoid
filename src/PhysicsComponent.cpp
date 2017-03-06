#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(	const glm::vec2 & position,
									const glm::vec2 & size,
									const glm::vec2 & velocity,
									const glm::vec2 & acceleration,
									const glm::vec2 & frictionCoeff)
	:
	position(position),
	size(size),
	velocity(velocity),
	acceleration(acceleration),
	frictionCoeff(frictionCoeff)
{}