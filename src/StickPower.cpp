#include "StickPower.h"
#include "PowerEvents.h"
#include "PhysicsComponent.h"
#include "ofLog.h"

void UseStickEventHandler::receive(const UseStickEvent & e)
{
	Entity stuck = e.stickable;
	Entity to = e.to;

	ComponentHandle<PhysicsComponent> stuckPhy = stuck.component<PhysicsComponent>();
	ComponentHandle<PhysicsComponent> toPhy = to.component<PhysicsComponent>();
	if (stuckPhy && toPhy)
	{
		stuckPhy->frictionCoeff = glm::vec2(0);
		stuckPhy->velocity.y = -e.releaseSpeed;
		// maybe add some horizontal speed too? adding paddle speed
		stuckPhy->velocity.x = toPhy->velocity.x;

		// normalize to ball speed
		stuckPhy->velocity /= stuckPhy->velocity.size();
		stuckPhy->velocity *= e.releaseSpeed;
	}
	else
	{
		ofLogError("PowerupSystem") << "Stickable or to does not have a physics component";
	}
}

StickCollisionHandler::StickCollisionHandler(float maxStickTime, float releaseSpeed)
	:
	maxStickTime(maxStickTime),
	releaseSpeed(releaseSpeed)
{}

void StickCollisionHandler::receive(const StickCollision & e)
{
	Entity to = e.to;
	to.assign<StickComponent>(e.stickable, maxStickTime, releaseSpeed);
}

