#pragma once

#include "ofxEntityX.h"

class BallSystem : public System<BallSystem>
{
public:
	BallSystem();

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

private:

};
