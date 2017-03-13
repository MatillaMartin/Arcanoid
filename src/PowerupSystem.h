#pragma once

#include "ofxEntityX.h"
#include "StickComponent.h"
#include "LevelEvents.h"

class PowerupSystem :	public System<PowerupSystem>
{
public:
	void configure(EventManager & eventManager);

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

};