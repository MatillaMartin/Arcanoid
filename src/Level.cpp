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
	m_visuals(visuals),
	m_tileVisuals(visuals.tileMatrixRegion, params.tiles->matrixWidth, params.tiles->matrixHeight)
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
		glm::size2 tilePosition(col, row);

		// map position to correct position with respect to layout
		tilePosition = m_visuals.tileMatrixRegion.map(tilePosition);

		unsigned int tileWidth = m_tileVisuals.tileSize.x;
		unsigned int tileHeight = m_tileVisuals.tileSize.y;

		entityx::Entity entity = entities.create();
		// common values for all tiles
		entity.assign<PositionComponent>(tilePosition);
		entity.assign<BoxCollisionComponent>(m_tileVisuals.tileSize);

		switch (tiletype)
		{
		case TileMatrix::EMPTY:
			continue;
			break;
		case TileMatrix::BASIC:
		{
			entity.assign<BasicVisualComponent>(m_tileVisuals.tileSize);
			entity.assign<LifeComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entity.assign<StrongVisualComponent>(m_tileVisuals.tileSize);
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
	//systems.update<CollisionSystem>(delta);
	//systems.update<BoundsSystem>(delta);
	//systems.update<MovementSystem>(delta);
	//systems.update<DebugSystem>(delta);
}

void Level::draw()
{
	entities.each<PositionComponent, BasicVisualComponent>(
		[this](Entity entity, PositionComponent & position, BasicVisualComponent & visual)
	{
		ofTexture & tex = m_visuals.tileTextures.at(visual.visual);
		tex.bind();
		ofDrawRectangle(position.position, visual.size.x, visual.size.y);
		tex.unbind();
	});

}