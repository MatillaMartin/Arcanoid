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
	CircleCollision(const glm::vec2 & center, float radius) : center(center), radius(radius) {}
	glm::vec2 center;
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
	CollisionInfo(bool bounce, bool fixed) : bBounce(bounce), bFixed(fixed) {}

	bool bBounce;
	bool bFixed;
};

class PhysicsComponent : public Component<PhysicsComponent>
{
public:
	PhysicsComponent(const PhysicsInfo & physics);
	PhysicsComponent(const PhysicsInfo & physics, const BoxCollision & box, const CollisionInfo & collision, b2World * world);
	PhysicsComponent(const PhysicsInfo & physics, const CircleCollision & circle, const CollisionInfo & info, b2World * world);
	PhysicsComponent(const PhysicsInfo & physics, const EdgeCollision & edge, const CollisionInfo & info, b2World * world);

	std::shared_ptr<ofxBox2dBaseShape> collision;

	void setVelocity(const glm::vec2 & vel);
	glm::vec2 getVelocity();
	void setAcceleration(const glm::vec2 & acc);
	glm::vec2 getAcceleration();
	void setFrictionCoeff(const glm::vec2 & coeff);
	glm::vec2 getFrictionCoeff();

private:
	PhysicsInfo physics;
	void setCollision(std::shared_ptr<ofxBox2dBaseShape> shape, const CollisionInfo & info);
};