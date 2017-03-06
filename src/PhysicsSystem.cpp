#include "PhysicsSystem.h"

void PhysicsSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<PhysicsComponent>([dt](Entity & entity, PhysicsComponent & physics)
	{
		physics.acceleration = -physics.velocity * physics.frictionCoeff;
		physics.velocity += physics.acceleration * dt;
		physics.position += physics.velocity * dt;
	});
}
