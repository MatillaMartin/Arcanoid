#include "PaddleSystem.h"

#include "PhysicsComponent.h"
#include "PaddleControllerComponent.h"
#include "UserCommand.h"
#include "CommandQueueComponent.h"
#include "LevelEvents.h"
#include "PowerEvents.h"
#include "TypeComponent.h"
#include "StickComponent.h"

PaddleSystem::PaddleSystem()
{}

void PaddleSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<PhysicsComponent, CommandQueueComponent, PaddleControllerComponent>([this, &events](Entity & e, PhysicsComponent & physics, CommandQueueComponent & commands, PaddleControllerComponent & controller)
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
				// call power event if any
				onPaddleUse(e, events);
				break;
			default:
				break;
			}
		}
	});
}

void PaddleSystem::onPaddleUse(Entity paddle, EventManager & events)
{
	auto type = paddle.component<TypeComponent<PowerType>>();
	if (!type)
	{
		ofLogError("PaddleSystem") << "Paddle does not have a PowerType component";
		return;
	}

	switch (type->type)
	{
	case PowerType::NONE:
		break;
	case PowerType::STICK:
	{
		ofLogVerbose("PaddleSystem") << "Paddle use called Stick power";
		auto stick = paddle.component<StickComponent>();
		events.emit<UseStickEvent>(stick->stickable, paddle, stick->releaseSpeed);
		paddle.remove<StickComponent>();
		type->type = PowerType::NONE;
		break;
	}
	case PowerType::SHOOT:
	{
		// emit shoot event
		break;
	}
	default:
		break;
	}
}
