#include "CollisionSystem.h"

#include "PositionComponent.h"
#include "CollisionComponent.h"

CollisionSystem::CollisionSystem(ofxBox2d * box2d)
	:
	m_box2d(box2d)
{
	assert(box2d); // we need an instance!
}

void CollisionSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	// update internal box2d collision and physics
	m_box2d->update();

	entities.each<PositionComponent, CollisionComponent>([](Entity & entity, PositionComponent & position, CollisionComponent & collision) 
	{
		// update position with resolved collision?
		position.position = collision.shape->getPosition();
	});
}
