#pragma once

#include "ofxEntityX.h"
#include "TypeComponent.h"
#include "SoundType.h"
#include "SoundPlayer.h"
#include "CollisionEvent.h"

class SoundSystem : public System<SoundSystem>, public Receiver<CollisionEvent>
{
public:
	typedef TypeComponent<SoundType> SoundTypeComponent;

	SoundSystem(SoundPlayer * player);

	void configure(EventManager &events) override;

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

	void receive(const CollisionEvent & e);

private:

	SoundPlayer * m_soundPlayer;

};