#include "Level.h"

#include "PositionComponent.h"
#include "BasicVisualComponent.h"
#include "StrongVisualComponent.h"
#include "LifeComponent.h"
#include "BoxCollisionComponent.h"

#include "TileMatrix.h"
#include "TileSystem.h"
#include "PlayerSystem.h"
#include "BallSystem.h"

Level::Level(const LevelParams & params)
	:
	m_params(params)
{
	createTiles();
}

void Level::createTiles()
{
	int index = -1;
	for (TileMatrix::TileType tiletype : m_params.tiles->matrix)
	{
		index++;

		if (tiletype == TileMatrix::EMPTY)
		{
			continue;
		}

		// determine normalized position
		unsigned int col = index % m_params.tiles->matrixWidth;
		unsigned int row = (index - col) / m_params.tiles->matrixWidth;
		ofVec2f tilePosition(col, row);

		double tileWidth = 1.0 / m_params.tiles->matrixWidth;
		double tileHeight = 1.0 / m_params.tiles->matrixHeight;

		entityx::Entity entity = entities.create();
		// common values for all tiles
		entity.assign<PositionComponent>(tilePosition);
		entity.assign<BoxCollisionComponent>(tileWidth, tileHeight);

		switch (tiletype)
		{
		case TileMatrix::EMPTY:
			continue;
			break;
		case TileMatrix::BASIC:
		{
			entity.assign<BasicVisualComponent>();
			entity.assign<LifeComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entity.assign<StrongVisualComponent>();
			entity.assign<LifeComponent>(2);
			break;
		}
		default:
			break;
		}
	}
}


void Level::update(double delta)
{

}

void Level::draw()
{

}