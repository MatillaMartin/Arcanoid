#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent(char left, char right, char up, char down, char use)
	:
	m_left(left),
	m_right(right),
	m_up(up),
	m_down(down),
	m_use(use)
{
}

bool PlayerInputComponent::parse(char input, UserCommand & command)
{
	if (input == m_left)
	{
		command = LEFT;
		return true;
	}
	if (input == m_right)
	{
		command = RIGHT;
		return true;
	}
	if (input == m_up)
	{
		command = UP;
		return true;
	}
	if (input == m_down)
	{
		command = DOWN;
		return true;
	}
	if (input == m_use)
	{
		command = USE;
		return true;
	}

	return false;
}
