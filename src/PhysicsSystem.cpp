#include "PhysicsSystem.h"
#include "PositionComponent.h"
#include "PhysicsComponent.h"

void PhysicsSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<PositionComponent, PhysicsComponent>([dt](Entity & entity, PositionComponent & position, PhysicsComponent & physics)
	{
		physics.setAcceleration( -physics.getVelocity() * physics.getFrictionCoeff() );
		physics.setVelocity( physics.getVelocity() + physics.getAcceleration() * dt );
		//position.position += physics.getVelocity() * dt;

		if (physics.collision)
		{
			position.position = physics.collision->getPosition();
		}
	});
}
