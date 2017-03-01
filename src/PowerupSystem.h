#pragma once

#include "ofxEntityX.h"

class PowerupSystem : public System<PowerupSystem>
{
public:
	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

};