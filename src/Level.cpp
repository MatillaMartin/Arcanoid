#include "Level.h"

#include "BasicVisualComponent.h"
#include "StrongVisualComponent.h"

Level::Level(const LevelParams & params)
	:
	m_params(params)
{
	createTiles();
}

void Level::createTiles()
{
	m_tiles.reserve(m_params.tiles->matrix.size());

	unsigned int index = 0;
	for (TileMatrix::TileType tiletype : m_params.tiles->matrix)
	{
		unsigned int col = index % m_params.tiles->matrixWidth;
		unsigned int row = (index - col) / m_params.tiles->matrixWidth;
		ofVec2f tilePosition(col, row);

		index++;

		switch (tiletype)
		{
		case TileMatrix::EMPTY:
			continue;
			break;
		case TileMatrix::BASIC:
		{
			entityx::Entity entity = entities.create();
			entity.assign<PositionComponent>(tilePosition);
			entity.assign<BasicVisualComponent>();
			entity.assign<LifeComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entityx::Entity entity = entities.create();
			entity.assign<PositionComponent>(tilePosition);
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