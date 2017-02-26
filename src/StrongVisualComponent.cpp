#include "StrongVisualComponent.h"

StrongVisualComponent::StrongVisualComponent(const glm::size & size) 
	: 
	TileVisualComponent(STRONG_1, size)
{
}

// behaviour in component, should be in system? is this really a behaviour? not a game mechanic, its visual
void StrongVisualComponent::onHit() 
{
	if (visual == STRONG_1)
	{
		visual = STRONG_0;
	}

	// other cases the tile will be removed
}
