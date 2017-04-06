#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"
#include "ofxBox2dBaseShape.h"

struct BoxCollision
{
	BoxCollision(const glm::vec2 & position, const glm::vec2 & size) : position(position), size(size) {}
	glm::vec2 position;
	glm::vec2 size;
};

struct CircleCollision
{
	CircleCollision(const glm::vec2 & position, float radius) : position(position), radius(radius) {}
	glm::vec2 position;
	float radius;
};

struct EdgeCollision
{
	EdgeCollision(const glm::vec2 & start, const glm::vec2 & end) : start(start), end(end) {}
	glm::vec2 start;
	glm::vec2 end;
};

struct PhysicsInfo
{
	PhysicsInfo(const glm::vec2 & velocity = glm::vec2(),
				const glm::vec2 & acceleration = glm::vec2(),
				const glm::vec2 & frictionCoeff = glm::vec2())
		: 
		velocity(velocity),
		acceleration(acceleration),
		frictionCoeff(frictionCoeff) 
	{}

	glm::vec2 frictionCoeff;
	glm::vec2 velocity;
	glm::vec2 acceleration;
};

struct CollisionInfo
{
	CollisionInfo(bool bounce, b2BodyType type) : bBounce(bounce), type(type) {}

	bool bBounce;
	b2BodyType type;
};

class PhysicsComponent : public Component<PhysicsComponent>
{
public:
	PhysicsComponent(Entity entity, const PhysicsInfo & physics);
	PhysicsComponent(Entity entity, const PhysicsInfo & physics, const BoxCollision & box, const CollisionInfo & collision, b2World * world);
	PhysicsComponent(Entity entity, const PhysicsInfo & physics, const CircleCollision & circle, const CollisionInfo & info, b2World * world);
	PhysicsComponent(Entity entity, const PhysicsInfo & physics, const EdgeCollision & edge, const CollisionInfo & info, b2World * world);

	~PhysicsComponent();

	std::shared_ptr<ofxBox2dBaseShape> collision;

	void setVelocity(const glm::vec2 & vel);
	glm::vec2 getVelocity();
	void setAcceleration(const glm::vec2 & acc);
	glm::vec2 getAcceleration();
	void setFrictionCoeff(const glm::vec2 & coeff);
	glm::vec2 getFrictionCoeff();

private:
	PhysicsInfo m_physics;
	Entity m_entity;
	void setPhysics(std::shared_ptr<ofxBox2dBaseShape> shape, const CollisionInfo & info);
	void setBody(CollisionInfo & info);
};