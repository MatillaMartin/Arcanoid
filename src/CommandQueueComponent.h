#pragma once

#include "ofxEntityX.h"
#include "UserCommand.h"
#include <queue>


class CommandQueueComponent : public Component<CommandQueueComponent>
{
public:

	void setCommand(UserCommand command);
	bool getCommand(UserCommand & command);
	void clear();

private:
	std::queue<UserCommand> m_commands;
};