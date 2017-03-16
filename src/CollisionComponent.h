#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"

enum class CollisionType { CIRCLE, BOX };

struct CollisionInfo
{
	bool bBounce;
};

class BoxCollisionComponent : public Component<BoxCollisionComponent>
{
public:
	BoxCollisionComponent(const glm::vec2 & position, const glm::vec2 & size, const CollisionInfo & info);

	glm::vec2 position;
	glm::vec2 size;
	CollisionInfo info;
};

class CircleCollisionComponent : public Component<CircleCollisionComponent>
{
public:
	CircleCollisionComponent(const glm::vec2 & center, float radius, const CollisionInfo & info);

	glm::vec2 center;
	float radius;
	CollisionInfo info;
};