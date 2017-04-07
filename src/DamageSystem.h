#pragma once

#include "ofxEntityX.h"
#include "CollisionEvent.h"

class DamageSystem : public System<DamageSystem>, public Receiver<DamageSystem>
{
public:
	DamageSystem(EventManager * events);
	
	void configure(EventManager & events) override;
	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

	void receive(const CollisionEvent & e);

private:
	void dealDamage(Entity from, Entity to);
	EventManager * m_events;
};