#include "PhysicsComponent.h"

#include "ofxBox2dRect.h"
#include "ofxBox2dCircle.h"
#include "ofxBox2dEdge.h"

PhysicsComponent::PhysicsComponent(const PhysicsInfo & physics)
	:
	physics(physics)
{
}

PhysicsComponent::PhysicsComponent(const PhysicsInfo & physics, const BoxCollision & box, const CollisionInfo & collision, b2World * world)
	:
	PhysicsComponent(physics)
{
	auto shape = make_shared<ofxBox2dRect>();
	shape->setup(world, box.position.x, box.position.y, box.size.x, box.size.y);

	setCollision(shape, collision);
}

PhysicsComponent::PhysicsComponent(const PhysicsInfo & physics, const CircleCollision & circle, const CollisionInfo & collision, b2World * world)
	:
	PhysicsComponent(physics)
{
	auto shape = make_shared<ofxBox2dCircle>();
	shape->setup(world, circle.center.x, circle.center.y, circle.radius);

	setCollision(shape, collision);
}

PhysicsComponent::PhysicsComponent(const PhysicsInfo & physics, const EdgeCollision & edge, const CollisionInfo & collision, b2World * world)
	:
	PhysicsComponent(physics)
{
	auto shape = make_shared<ofxBox2dEdge>();
	shape->addVertex(glm::vec3(edge.start.xy, 0.0f));
	shape->addVertex(glm::vec3(edge.end.xy, 0.0f));
	shape->create(world);

	setCollision(shape, collision);
}

void PhysicsComponent::setVelocity(const glm::vec2 & vel)
{
	// keep velocity updated
	if (collision)
	{
		collision->setVelocity(vel);
	}
	
	physics.velocity = vel;
}

glm::vec2 PhysicsComponent::getVelocity()
{
	// keep velocity updated
	if (collision)
	{
		physics.velocity = collision->getVelocity();
	}
	return physics.velocity;
}

void PhysicsComponent::setAcceleration(const glm::vec2 & acc)
{
	physics.acceleration = acc;
}

glm::vec2 PhysicsComponent::getAcceleration()
{
	return physics.acceleration;
}

void PhysicsComponent::setFrictionCoeff(const glm::vec2 & coeff)
{
	physics.frictionCoeff = coeff;
}

glm::vec2 PhysicsComponent::getFrictionCoeff()
{
	return physics.frictionCoeff;
}

void PhysicsComponent::setCollision(std::shared_ptr<ofxBox2dBaseShape> shape, const CollisionInfo & info)
{
	this->collision = shape;

	if (info.bFixed) {
		collision->body->SetType(b2BodyType::b2_staticBody);
	}
	else {
		collision->body->SetType(b2BodyType::b2_dynamicBody);
	}

	if (info.bBounce) {
		collision->setBounce(1.0f);
	}
	else {
		collision->setBounce(0.0f);
	}
}