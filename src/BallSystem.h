#pragma once

#include "ofxEntityX.h"

class BallSystem : public System<BallSystem>
{
public:
	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

private:

};
