#pragma once

#include "ofxEntityX.h"
#include <queue>
#include "UserCommand.h"

class PaddleControllerComponent : public Component<PaddleControllerComponent>
{
public:

	struct PaddleParams
	{
		float speed;
	};

	PaddleControllerComponent(const PaddleParams & params = PaddleParams());
	
	void setCommand(UserCommand command);
	bool getCommand(UserCommand & command);

	PaddleParams params;

private:
	// join commands with controller. Component is a place to save data really..
	std::queue<UserCommand> m_commands;
};