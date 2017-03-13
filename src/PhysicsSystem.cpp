#include "PhysicsSystem.h"
#include "PositionComponent.h"
#include "PhysicsComponent.h"

void PhysicsSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<PositionComponent, PhysicsComponent>([dt](Entity & entity, PositionComponent & position, PhysicsComponent & physics)
	{
		physics.acceleration = -physics.velocity * physics.frictionCoeff;
		physics.velocity += physics.acceleration * dt;
		position.position += physics.velocity * dt;
	});
}
