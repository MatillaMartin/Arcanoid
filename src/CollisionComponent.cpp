#include "CollisionComponent.h"

CollisionComponent::CollisionComponent()
	:
	info{ false, false }
{}

CollisionComponent::CollisionComponent(const CollisionInfo & info)
	:
	info(info)
{}

CollisionComponent::CollisionComponent(b2World * world, const BoxCollision & box, const CollisionInfo & info)
	:
	CollisionComponent(info)
{
	auto boxShape = make_shared<ofxBox2dRect>();
	shape = boxShape;
	boxShape->setup(world, box.position.x, box.position.y, box.size.x, box.size.y);
	setInfo();
}

CollisionComponent::CollisionComponent(b2World * world, const CircleCollision & circle, const CollisionInfo & info)
	:
	CollisionComponent(info)
{
	auto circleShape = make_shared<ofxBox2dCircle>();
	shape = circleShape;
	circleShape->setup(world, circle.center.x, circle.center.y, circle.radius);
	setInfo();
}

CollisionComponent::CollisionComponent(b2World * world, const EdgeCollision & edge, const CollisionInfo & info)
	:
	CollisionComponent(info)
{
	auto edgeShape = make_shared<ofxBox2dEdge>();
	shape = edgeShape;
	edgeShape->addVertex(glm::vec3(edge.start.xy, 0.0f));
	edgeShape->addVertex(glm::vec3(edge.end.xy, 0.0f));
	edgeShape->create(world);
	setInfo();
}

void CollisionComponent::setInfo()
{
	if (info.bFixed) {
		shape->body->SetType(b2BodyType::b2_staticBody);
	}
	else {
		shape->body->SetType(b2BodyType::b2_dynamicBody);
	}
	
	if (info.bBounce) {
		shape->setBounce(1.0f);
	}
	else {
		shape->setBounce(0.0f);
	}
}