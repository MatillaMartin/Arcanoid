#pragma once

#include "ofxEntityX.h"
#include "ofxBox2d.h"

class CollisionSystem : public System<CollisionSystem>
{
public:
	CollisionSystem(ofxBox2d * box2d, EventManager * events);
	~CollisionSystem();

	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;
	
	void onCollision(ofxBox2dContactArgs & args);

	ofxBox2d * m_box2d;
	EventManager * m_events;
};