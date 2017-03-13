#include "PowerupSystem.h"
#include "PhysicsComponent.h"
#include "ofLog.h"

void PowerupSystem::configure(EventManager & eventManager)
{
}

void PowerupSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<StickComponent>([dt](Entity & entity, StickComponent & stick) 
	{
		stick.currentStickTime += dt;
		if (stick.currentStickTime > stick.maxStickTime)
		{
			// remove the stick component
			entity.remove<StickComponent>();
		}
	});

	// update other powerups
}



//void PowerupSystem::receive(const UseEvent & use)
//{
//	// what to do when receiving the use event?
//}
//
//void PowerupSystem::receive(const ComponentAddedEvent<StickComponent>& stickAdded)
//{
//	// stick shall set to zero the velocity and acceleration of the stuck entity once added
//	Entity sticked = stickAdded.component->who;
//	ComponentHandle<PhysicsComponent> physics = sticked.component<PhysicsComponent>();
//	if (physics)
//	{
//		physics->velocity = glm::vec2(0);
//		physics->acceleration = glm::vec2(0);
//	}
//	else
//	{
//		ofLogError("PowerupSystem") << "Sticked does not have a physics component";
//	}
//}
//
//void PowerupSystem::receive(const ComponentRemovedEvent<StickComponent>& stickRemoved)
//{
//	Entity sticked = stickRemoved.component->who;
//	Entity to = stickRemoved.entity;
//
//	ComponentHandle<PhysicsComponent> physicsSticked = sticked.component<PhysicsComponent>();
//	ComponentHandle<PhysicsComponent> phyiscsTo = to.component<PhysicsComponent>();
//	if (physicsSticked && phyiscsTo)
//	{
//		physicsSticked->velocity.y = stickRemoved.component->releaseSpeed;
//		// maybe add some horizontal speed too? adding paddle speed
//		physicsSticked->velocity.x = phyiscsTo->velocity.x;
//	}
//	else
//	{
//		ofLogError("PowerupSystem") << "Sticked or to does not have a physics component";
//	}
//}