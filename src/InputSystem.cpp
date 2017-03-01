#include "InputSystem.h"

#include "PlayerInputComponent.h"
#include "PaddleControllerComponent.h"

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
		entities.each<PlayerInputComponent, PaddleControllerComponent>([input](Entity entity, PlayerInputComponent & player, PaddleControllerComponent & paddle)
		{
			UserCommand command;
			// forwarad command to paddle if the player input has a command for that input
			if (player.getCommand(input, command))
			{
				paddle.setCommand(command);
			}
		});

		// if there are more entities that require user input then update them too (menu?)
	}
}
