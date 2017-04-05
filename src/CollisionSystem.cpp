#include "CollisionSystem.h"
#include "CollisionEvent.h"

CollisionSystem::CollisionSystem(ofxBox2d * box2d, EventManager * events)
	:
	m_box2d(box2d),
	m_events(events)
{
	assert(box2d); // we need an instance!

	m_box2d->enableEvents();
	ofAddListener(m_box2d->contactEndEvents, this, &CollisionSystem::onCollision);
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	// update internal box2d collision and physics
	m_box2d->update();
}

void CollisionSystem::onCollision(ofxBox2dContactArgs & args)
{
	// assumes PhysicsComponent has set the entity id in the user data
	assert(args.a->GetBody()->GetUserData() != nullptr);
	assert(args.b->GetBody()->GetUserData() != nullptr);

	Entity a = *(Entity*)args.a->GetBody()->GetUserData();
	Entity b = *(Entity*)args.b->GetBody()->GetUserData();

	m_events->emit<CollisionEvent>({ a, b });
}
