#pragma once

#include "ofxEntityX.h"
#include "SelectComponent.h"

class SelectSystem : public System<SelectSystem>
{
public:
	SelectSystem();

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

private:

	void nextItem(SelectComponent & select, EventManager & events);
	void previousItem(SelectComponent & select, EventManager & events);
	void useItem(SelectComponent & select, EventManager & events);
};