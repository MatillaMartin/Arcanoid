#include "PaddleSystem.h"

#include "PhysicsComponent.h"
#include "PaddleControllerComponent.h"
#include "UserCommand.h"
#include "CommandQueueComponent.h"
#include "LevelEvents.h"

PaddleSystem::PaddleSystem()
{}

void PaddleSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<PhysicsComponent, CommandQueueComponent, PaddleControllerComponent>([dt, &events](Entity & e, PhysicsComponent & physics, CommandQueueComponent & commands, PaddleControllerComponent & controller)
	{
		UserCommand command;
		while (commands.getCommand(command))
		{
			switch (command)
			{
			case UserCommand::LEFT:
				physics.velocity.x = -controller.params.speed;
				break;
			case UserCommand::RIGHT:
				physics.velocity.x = controller.params.speed;
				break;
			case UserCommand::USE:
				events.emit<UseEvent>(e);
				break;
			default:
				break;
			}
		}
	});
}
