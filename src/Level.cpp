#include "Level.h"
#include "TileMatrix.h"

#include "PhysicsComponent.h"
#include "HitsComponent.h"

#include "TileVisualComponent.h"
#include "PaddleVisualComponent.h"
#include "BallVisualComponent.h"

#include "BoxCollisionComponent.h"
#include "CircleCollisionComponent.h"

#include "PaddleControllerComponent.h"

#include "TileSystem.h"
#include "CollisionSystem.h"
#include "PaddleSystem.h"
#include "BallSystem.h"
#include "InputSystem.h"
#include "PowerupSystem.h"

#include "PlayerInputComponent.h"

#include "Events.h"

#include "ofGraphics.h"

Level::Level(const LevelParams & params, const LevelVisuals & visuals, std::function<void()> onLevelEnd)
	:
	m_params(params),
	m_visuals(visuals),
	m_tileVisuals(visuals.tileMatrixRegion, params.tiles->matrixWidth, params.tiles->matrixHeight),
	m_paddleVisuals(visuals.paddleSize.x, visuals.paddleSize.y),
	m_ballVisuals(visuals.ballRadius),
	m_levelEndHandler(onLevelEnd)
{
	setupEntityX();
	createTiles();
	createPaddle();
	createBall();
}

void Level::setupEntityX()
{
	systems.add<InputSystem>();
	systems.add<TileSystem>(m_params.tiles->count());
	systems.add<CollisionSystem>();
	systems.add<PaddleSystem>();
	systems.add<BallSystem>();
	systems.add<PowerupSystem>();
	systems.configure();

	this->events.subscribe<LevelEndEvent>(m_levelEndHandler);
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
		entity.assign<PhysicsComponent>(tilePosition);
		entity.assign<BoxCollisionComponent>(m_tileVisuals.tileSize);

		switch (tiletype)
		{
		case TileMatrix::EMPTY:
			continue;
			break;
		case TileMatrix::BASIC:
		{
			entity.assign<TileVisualComponent>(TileTexture::BASIC, m_tileVisuals.tileSize);
			entity.assign<HitsComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entity.assign<TileVisualComponent>(TileTexture::STRONG_1, m_tileVisuals.tileSize);
			entity.assign<HitsComponent>(2);
			break;
		}
		default:
			break;
		}
	}
}

void Level::createPaddle()
{
	// map position to correct position with respect to layout
	glm::vec2 paddlePosition = m_visuals.levelRegion.map(m_params.paddlePosition);
	m_paddle = entities.create();
	m_paddle.assign<PhysicsComponent>(paddlePosition);
	m_paddle.assign<BoxCollisionComponent>(m_paddleVisuals.paddleSize);
	m_paddle.assign<PaddleVisualComponent>(m_paddleVisuals.paddleSize);
	m_paddle.assign<PlayerInputComponent>('a', 'd', 0, 0, ' ');

	PaddleControllerComponent::PaddleParams params;
	params.speed = m_params.paddleSpeed;
	params.friction = m_params.paddleFriction;
	m_paddle.assign<PaddleControllerComponent>();
}

void Level::createBall()
{
	// find initial location relative to the paddle
	glm::vec2 ballPosition = m_paddle.component<PhysicsComponent>()->position;
	ballPosition.x += m_paddle.component<PaddleVisualComponent>()->size.x / 2.0f;
	ballPosition.y -= m_ballVisuals.ballSize;

	m_ball = entities.create();
	m_ball.assign<PhysicsComponent>(ballPosition);
	m_ball.assign<CircleCollisionComponent>(m_ballVisuals.ballSize);
	m_ball.assign<BallVisualComponent>(m_ballVisuals.ballSize);
}


void Level::update(double delta)
{
	systems.update<InputSystem>(delta);
	systems.update<CollisionSystem>(delta);
	systems.update<TileSystem>(delta);
	systems.update<PaddleSystem>(delta);
	systems.update<BallSystem>(delta);
	systems.update<PowerupSystem>(delta);
}

void Level::draw(Renderer * renderer)
{
	entities.each<PhysicsComponent, TileVisualComponent>(
		[this](Entity entity, PhysicsComponent & physics, TileVisualComponent & visual)
	{
		ofTexture tex = m_visuals.tileTextures.at(visual.visual);

		m_tileVisuals.tileShader.begin();
		m_tileVisuals.tileShader.setUniform2f("tileDisplacement", physics.position);
		m_tileVisuals.tileShader.setUniformTexture("tileTexture", tex, 0);
			m_tileVisuals.tileQuad.draw();
		m_tileVisuals.tileShader.end();
	});

	m_paddleVisuals.paddleShader.begin();
	m_paddleVisuals.paddleShader.setUniform2f("paddleDisplacement", m_paddle.component<PhysicsComponent>()->position);
	m_paddleVisuals.paddleShader.setUniformTexture("paddleTexture", m_visuals.paddleTexture, 0);
	m_paddleVisuals.paddleQuad.draw();
	m_paddleVisuals.paddleShader.end();

	m_ballVisuals.ballShader.begin();
	m_ballVisuals.ballShader.setUniform2f("ballDisplacement", m_ball.component<PhysicsComponent>()->position);
	m_ballVisuals.ballShader.setUniformTexture("ballTexture", m_visuals.ballTexture, 0);
	m_ballVisuals.ballQuad.draw();
	m_ballVisuals.ballShader.end();
}

void Level::input(char input)
{
	systems.system<InputSystem>()->onInput(input);
}
