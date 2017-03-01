#include "PaddleControllerComponent.h"

PaddleControllerComponent::PaddleControllerComponent(const PaddleParams & params)
	:
	params(params)
{}

void PaddleControllerComponent::setCommand(UserCommand command)
{
	m_commands.push(command);
}

bool PaddleControllerComponent::getCommand(UserCommand & command)
{
	if (!m_commands.empty())
	{
		command = m_commands.front();
		m_commands.pop();
		return true;
	}
	return false;
}

