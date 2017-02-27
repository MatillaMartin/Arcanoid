#pragma once

#include "ofxEntityX.h"
#include "TileVisuals.h"
#include "TileVisualComponent.h"
#include "ofTexture.h"
class TileMatrix;

class Level : public ofxEntityX
{
public:
	class LevelParams
	{
	public:
		std::shared_ptr<TileMatrix> tiles;
		unsigned int time;
	};

	class LevelVisuals
	{
	public:
		map<TileVisualComponent::TileVisual, ofTexture> tileTextures;
		ofRectangle tileMatrixRegion;
	};

	Level(const LevelParams & params, const LevelVisuals & visuals);


	void update(double delta);
	void draw();

	LevelParams m_params;
	LevelVisuals m_visuals;

	TileVisuals m_tileVisuals;

private:
	void setupEntityX();
	void createTiles();
};
