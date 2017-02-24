#pragma once

#include "ofxEntityX.h"

class TileMatrix;

class Level : public ofxEntityX
{
	struct LevelParams
	{
		std::shared_ptr<TileMatrix> tiles;
		unsigned int time;
	};

	struct LevelVisuals
	{
		ofRectangle tileMatrixRegion;
	};

	struct TileVisuals
	{
		glm::size2 tileSize;
		map<TileVisualComponent::TileVisual, ofTexture> m_tileTextures;
	};

	Level(const LevelParams & params, const LevelVisuals & visuals);

	void update(double delta);
	void draw();

	LevelParams m_params;
	LevelVisuals m_visuals;

	TileVisuals m_tileVisuals;

private:
	void createTiles();
};
