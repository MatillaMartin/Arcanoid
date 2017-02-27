#pragma once
#include "ofRectangle.h"
#include "ofVboMesh.h"
#include "ofShader.h"

class TileVisuals
{
public:
	TileVisuals(const ofRectangle & tileMatrixRegion, float nTilesWidth, float nTilesHeight);
	glm::vec2 tileSize;
	ofVboMesh tileQuad;
	ofShader tileShader;
};
