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

#include "ofGraphics.h"

Level::Level(const LevelParams & params, const LevelVisuals & visuals)
	:
	m_params(params),
	m_visuals(visuals)
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
			entity.assign<BasicVisualComponent>(tileWidth, tileHeight);
			entity.assign<LifeComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entity.assign<StrongVisualComponent>(tileWidth, tileHeight);
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
	systems.update<CollisionSystem>(dt);
	systems.update<BoundsSystem>(dt);
	systems.update<MovementSystem>(dt);
	systems.update<DebugSystem>(dt);
}

void Level::draw()
{
	entities.each<PositionComponent, BasicVisualComponent>(
		[this](Entity entity, PositionComponent & position, BasicVisualComponent & visual)
	{
		ofVec2f pos = position * this->m_visuals.tileMatrixRegion // TODO get postion of tile in rect
	}
	);
}