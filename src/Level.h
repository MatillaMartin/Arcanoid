#pragma once

#include "TileMatrix.h"
#include "TileSystem.h"
#include "PlayerSystem.h"
#include "BallSystem.h"
#include "Tile.h"
#include "ofxEntityX.h"

class Level : public ofxEntityX
{
	struct LevelParams
	{
		std::shared_ptr<TileMatrix> tiles;
		unsigned int time;
	};

	Level(const LevelParams & params);

	void update(double delta);
	void draw();

	LevelParams m_params;

	vector<Tile> m_tiles;

private:
	void createTiles();
};
