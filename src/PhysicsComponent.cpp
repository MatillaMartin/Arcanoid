#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(	const glm::vec2 & velocity, 
									const glm::vec2 & acceleration, 
									const glm::vec2 & frictionCoeff)
	:
	velocity(velocity),
	acceleration(acceleration),
	frictionCoeff(frictionCoeff)
{}
