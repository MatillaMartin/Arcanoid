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

	Level(const LevelParams & params);

	void update(double delta);
	void draw();

	LevelParams m_params;

private:
	void createTiles();
};
