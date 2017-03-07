#pragma once

#include "ofxEntityX.h"
#include "UserCommand.h"
#include <queue>


class CommandQueueComponent : public System<CommandQueueComponent>
{
public:

	void setCommand(UserCommand command);
	bool getCommand(UserCommand & command);

private:
	std::queue<UserCommand> m_commands;
};