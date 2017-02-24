#include "StrongVisualComponent.h"

StrongVisualComponent::StrongVisualComponent() : TileVisualComponent(STRONG_1)
{
}

void StrongVisualComponent::onHit()
{
	if (visual == STRONG_1)
	{
		visual == STRONG_0;
	}

	// other cases the tile will be removed
}
