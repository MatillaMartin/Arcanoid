#include "InputSystem.h"

#include "KeyboardInputComponent.h"
#include "CommandQueueComponent.h"

InputSystem::InputSystem()
{
}

void InputSystem::onInput(char input)
{
	m_input.push(input);
}

void InputSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	while(!m_input.empty())
	{
		char input = m_input.front();
		m_input.pop();
		entities.each<KeyboardInputComponent, CommandQueueComponent>([input](Entity & entity, KeyboardInputComponent & keyboard, CommandQueueComponent & commands)
		{
			UserCommand command;
			// forward command to queue if keyboard input component has a command for that input
			if (keyboard.parse(input, command))
			{
				commands.setCommand(command);
			}
		});
	}
}
