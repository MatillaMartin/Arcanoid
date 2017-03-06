#pragma once

#include "ofxEntityX.h"
#include "PhysicsComponent.h"

class PhysicsSystem : public System<PhysicsSystem>
{
public:

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;
};