#include "BasicVisualComponent.h"

BasicVisualComponent::BasicVisualComponent(const glm::size & size) 
	:
	TileVisualComponent(BASIC, size)
{}

void BasicVisualComponent::onHit()
{
	// no changes here
}
