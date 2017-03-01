#pragma once

#include "ofxEntityX.h"

class CollisionSystem : public System<CollisionSystem>
{
public:
	CollisionSystem();

	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;
};