#pragma once

#include "ofxEntityX.h"
#include "StickComponent.h"
#include "LevelEvents.h"
#include "PowerEvents.h"

class PowerSystem : public System<PowerSystem>
{
public:

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

};