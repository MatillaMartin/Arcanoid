#include "Level.h"

#include "PositionComponent.h"
#include "TileVisualComponent.h"
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
	setupEntityX();
	createTiles();
}

void Level::setupEntityX()
{
	systems.configure();
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
		float col = index % m_params.tiles->matrixWidth;
		float row = (index - col) / m_params.tiles->matrixWidth;
		glm::vec2 tilePosition(col, row);
		tilePosition /= glm::vec2(m_params.tiles->matrixWidth, m_params.tiles->matrixHeight);

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
			entity.assign<TileVisualComponent>(TileVisualComponent::BASIC, m_tileVisuals.tileSize);
			entity.assign<LifeComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entity.assign<TileVisualComponent>(TileVisualComponent::STRONG_1, m_tileVisuals.tileSize);
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
	entities.each<PositionComponent, TileVisualComponent>(
		[this](Entity entity, PositionComponent & position, TileVisualComponent & visual)
	{
		ofTexture & tex = m_visuals.tileTextures.at(visual.visual);

		m_tileVisuals.tileShader.begin();
		m_tileVisuals.tileShader.setUniform2f("tileDisplacement", position.position);
		m_tileVisuals.tileShader.setUniformTexture("tileTexture", tex, 0);
			m_tileVisuals.tileQuad.draw();
		m_tileVisuals.tileShader.end();
	});

}