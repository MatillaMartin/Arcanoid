#pragma once

#include "TileVisualComponent.h"

class BasicVisualComponent : public TileVisualComponent
{
public:
	BasicVisualComponent(const glm::size & size);
	void onHit() override;
};