#include "PaddleSystem.h"

#include "VelocityComponent.h"
#include "PaddleControllerComponent.h"

PaddleSystem::PaddleSystem()
{}

void PaddleSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<VelocityComponent, PaddleControllerComponent>([](Entity & e, VelocityComponent & velocity, PaddleControllerComponent & controller)
	{
		UserCommand command;
		while (controller.getCommand(command))
		{
			switch (command)
			{
			case UserCommand::LEFT:
				velocity.velocity.x = -controller.params.speed;
				break;
			case UserCommand::RIGHT:
				velocity.velocity.x = controller.params.speed;
				break;
			case UserCommand::USE:
				// INTERESTING
				break;
			default:
				break;
			}
		}
	});
}
