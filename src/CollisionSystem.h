#pragma once

#include "ofxEntityX.h"
#include "ofxBox2d.h"

class CollisionSystem : public System<CollisionSystem>
{
public:
	CollisionSystem(ofxBox2d * box2d = nullptr);

	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

	ofxBox2d * m_box2d;
};