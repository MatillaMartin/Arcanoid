#include "CommandQueueComponent.h"


void CommandQueueComponent::setCommand(UserCommand command)
{
	m_commands.push(command);
}

bool CommandQueueComponent::getCommand(UserCommand & command)
{
	if (!m_commands.empty())
	{
		command = m_commands.front();
		m_commands.pop();
		return true;
	}
	return false;
}

void CommandQueueComponent::clear()
{
	m_commands = {}; // clear using emtpy initializer list
}