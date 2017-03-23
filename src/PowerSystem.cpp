#include "PowerSystem.h"
#include "TypeComponent.h"
#include "PhysicsComponent.h"

void PowerSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	entities.each<TypeComponent<PowerType>>([dt, &events](Entity & entity, TypeComponent<PowerType> & power) 
	{
		switch (power.type)
		{
			case PowerType::NONE:
				break;

			case PowerType::STICK:
			{
				auto stick = entity.component<StickComponent>();

				if (!stick)
				{
					ofLogError("PowerSystem") << "Stick component not found, but PowerType was STICK";
					break;
				}

				// update stick time
				stick->currentStickTime += dt;
				auto physics = stick->stickable.component<PhysicsComponent>();
				if (physics)
				{
					auto entPhy = entity.component<PhysicsComponent>();
					if (entPhy)
					{
						physics->setFrictionCoeff(entPhy->getFrictionCoeff());
						physics->setVelocity(entPhy->getVelocity());
					}
					else
					{
						ofLogError("PowerSystem") << "Sticked to entity does not have a PhysicsComponent";
					}
				}
				else
				{
					ofLogError("PowerSystem") << "Stickable entity does not have a PhysicsComponent";
				}
				// if the stick time has passed
				if (stick->currentStickTime > stick->maxStickTime)
				{
					// send a use stick power event and remove the power
					events.emit<UseStickEvent>(stick->stickable, entity, stick->releaseSpeed);
					entity.remove<StickComponent>();
					power.type = PowerType::NONE;
				}
			}
			case PowerType::SHOOT:
			{
				// do something with shooting?
			}

		default:
			break;
		}
	});
}