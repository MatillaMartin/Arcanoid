#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"
#include "ofxBox2d.h"

enum class CollisionType { CIRCLE, BOX, EDGE };

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

struct CollisionInfo
{
	CollisionInfo(bool bounce, bool fixed) : bBounce(bounce), bFixed(fixed) {}

	bool bBounce;
	bool bFixed;
};

class CollisionComponent : public Component<CollisionComponent>
{
public:
	CollisionComponent();
	CollisionComponent(b2World * world, const BoxCollision & box, const CollisionInfo & info);
	CollisionComponent(b2World * world, const CircleCollision & circle, const CollisionInfo & info);
	CollisionComponent(b2World * world, const EdgeCollision & edge, const CollisionInfo & info);

	std::shared_ptr<ofxBox2dBaseShape> shape;
	CollisionInfo info;

private:
	CollisionComponent(const CollisionInfo & info);
	void setInfo();
};