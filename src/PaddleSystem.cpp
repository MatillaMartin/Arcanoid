#include "PaddleSystem.h"

#include "PhysicsComponent.h"
#include "PaddleControllerComponent.h"

PaddleSystem::PaddleSystem()
{}

void PaddleSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<PhysicsComponent, PaddleControllerComponent>([dt](Entity & e, PhysicsComponent & physics, PaddleControllerComponent & controller)
	{
		UserCommand command;
		while (controller.getCommand(command))
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
				// INTERESTING
				break;
			default:
				break;
			}
		}
	});
}
