#include "CollisionComponent.h"

BoxCollisionComponent::BoxCollisionComponent(const glm::vec2 & position, const glm::vec2 & size, const CollisionInfo & info)
	:
	position(position),
	size(size),
	info(info)
{
}

CircleCollisionComponent::CircleCollisionComponent(const glm::vec2 & center, float radius, const CollisionInfo & info)
	:
	center(center), 
	radius(radius),
	info(info)
{
}
