#pragma once

#include <queue>
#include "ofxEntityX.h"

class InputSystem : public System<InputSystem>
{
public:
	InputSystem();

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

	void onInput(char input);

private:
	std::queue<char> m_input;

};