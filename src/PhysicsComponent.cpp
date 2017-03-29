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
	this->collision = shape;

	setPhysics(shape, collision);
	shape->setup(world, box.position.x, box.position.y, box.size.x, box.size.y);
	shape->body->SetType(collision.type);
	shape->body->SetFixedRotation(true);
}

PhysicsComponent::PhysicsComponent(const PhysicsInfo & physics, const CircleCollision & circle, const CollisionInfo & collision, b2World * world)
	:
	PhysicsComponent(physics)
{
	auto shape = make_shared<ofxBox2dCircle>();
	this->collision = shape;

	setPhysics(shape, collision);
	shape->setup(world, circle.position.x, circle.position.y, circle.radius);
	shape->body->SetType(collision.type);
	shape->body->SetFixedRotation(true);
}

PhysicsComponent::PhysicsComponent(const PhysicsInfo & physics, const EdgeCollision & edge, const CollisionInfo & collision, b2World * world)
	:
	PhysicsComponent(physics)
{
	auto shape = make_shared<ofxBox2dEdge>();
	this->collision = shape;

	shape->addVertex(glm::vec3(edge.start.xy, 0.0f));
	shape->addVertex(glm::vec3(edge.end.xy, 0.0f));

	setPhysics(shape, collision);
	shape->create(world);
	shape->body->SetType(collision.type);
	shape->body->SetFixedRotation(true);
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

void PhysicsComponent::setPhysics(std::shared_ptr<ofxBox2dBaseShape> shape, const CollisionInfo & info)
{
	float density = 1.0f;
	float bounce = 1.0f;
	float friction = 0.0f;

	//if (info.bBounce) bounce = 1.0f;

	collision->setPhysics(density, bounce, friction);
}

void PhysicsComponent::setBody(CollisionInfo & info)
{

}