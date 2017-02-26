#pragma once
#include "ofRectangle.h"

class TileVisuals
{
public:
	TileVisuals(const ofRectangle & tileMatrixRegion, float nTilesWidth, float nTilesHeight);
	glm::vec2 tileSize;
};
