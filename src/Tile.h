#pragma once

#include "LifeComponent.h"
#include "VisualComponent.h"
#include "PositionComponent.h"

class Tile
{
public:
	Tile(const TileParams & params = TileParams());

	TileParams m_params;
};