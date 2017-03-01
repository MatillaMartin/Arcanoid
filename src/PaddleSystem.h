#pragma once

#include "ofxEntityX.h"

class PaddleSystem : public System<PaddleSystem>
{
public:
	PaddleSystem();

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

};