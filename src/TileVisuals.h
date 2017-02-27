#pragma once
#include "ofRectangle.h"
#include "ofVboMesh.h"
#include "ofShader.h"

class TileVisuals
{
public:
	TileVisuals(const ofRectangle & tileMatrixRegion, float nTilesWidth, float nTilesHeight);

	vector<glm::vec2> tilePositions;
	glm::vec2 tileSize;
	ofVboMesh tileQuad;
	ofShader tileShader;
};
