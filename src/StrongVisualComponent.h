#pragma once

#include "ofMath.h"
#include "TileVisualComponent.h"

class StrongVisualComponent : public TileVisualComponent
{
public:
	StrongVisualComponent(const glm::size & size);

	void onHit() override;
};