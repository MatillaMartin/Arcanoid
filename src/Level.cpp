#include "Level.h"
#include "TileMatrix.h"

#include "PhysicsComponent.h"
#include "HitsComponent.h"

#include "TileTextureComponent.h"
#include "PaddleTextureComponent.h"
#include "BallTextureComponent.h"

#include "BoxCollisionComponent.h"
#include "CircleCollisionComponent.h"

#include "PaddleControllerComponent.h"

#include "TileSystem.h"
#include "CollisionSystem.h"
#include "PaddleSystem.h"
#include "BallSystem.h"
#include "InputSystem.h"
#include "PowerupSystem.h"
#include "PhysicsSystem.h"

#include "PlayerInputComponent.h"

#include "Events.h"

#include "ofGraphics.h"

Level::Level(const LevelParams & params, const LevelVisuals & visuals, std::function<void()> onLevelEnd)
	:
	m_params(params),
	m_visuals(visuals),
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
	systems.add<TileSystem>(m_visuals.tileMap, m_params.tiles->count());
	systems.add<CollisionSystem>();
	systems.add<PaddleSystem>();
	systems.add<BallSystem>();
	systems.add<PowerupSystem>();
	systems.add<PhysicsSystem>();
	systems.configure();

	this->events.subscribe<LevelEndEvent>(m_levelEndHandler);
}

void Level::createTiles()
{
	// determine tile size from region
	ofRectangle region = m_visuals.levelRegion.map(m_visuals.tileMatrixRegion);

	glm::vec2 tileSize (region.width / m_params.tiles->nCols, region.height / m_params.tiles->nRows);

	int index = -1;
	for (TileMatrix::TileType tiletype : m_params.tiles->matrix)
	{
		index++;

		if (tiletype == TileMatrix::EMPTY)
		{
			continue;
		}

		// determine normalized position
		float col = index % m_params.tiles->nCols;
		float row = (index - col) / m_params.tiles->nCols;
		glm::vec2 tilePosition(col, row);
		tilePosition *= tileSize;
		
		entityx::Entity entity = entities.create();
		// common values for all tiles
		entity.assign<PhysicsComponent>(tilePosition, tileSize);
		entity.assign<BoxCollisionComponent>();

		switch (tiletype)
		{
		case TileMatrix::EMPTY:
			continue;
			break;
		case TileMatrix::BASIC:
		{
			entity.assign<TileTextureComponent>(TileType::BASIC, TileTexture::BASIC_0);
			entity.assign<HitsComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entity.assign<TileTextureComponent>(TileType::STRONG, TileTexture::STRONG_1);
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
	m_paddle.assign<PhysicsComponent>(paddlePosition, m_visuals.paddleSize, glm::vec2(), glm::vec2(), glm::vec2(m_params.paddleFrictionCoeff, 0.0f));
	m_paddle.assign<BoxCollisionComponent>();
	m_paddle.assign<PaddleTextureComponent>(PaddleTexture::PADDLE);
	m_paddle.assign<PlayerInputComponent>('a', 'd', 0, 0, ' ');

	PaddleControllerComponent::PaddleParams params;
	params.speed = m_params.paddleSpeed;
	m_paddle.assign<PaddleControllerComponent>(params);
}

void Level::createBall()
{
	// find initial location relative to the paddle
	ComponentHandle<PhysicsComponent> paddle = m_paddle.component<PhysicsComponent>();
	glm::vec2 ballPosition = paddle->position;
	ballPosition.x += paddle->size.x / 2.0f;
	ballPosition.y -= m_visuals.ballSize.y;

	m_ball = entities.create();
	m_ball.assign<PhysicsComponent>(ballPosition, m_visuals.ballSize);
	m_ball.assign<CircleCollisionComponent>();
	m_ball.assign<BallTextureComponent>(BallTexture::BALL);
}


void Level::update(double delta)
{
	systems.update<InputSystem>(delta);
	systems.update<TileSystem>(delta);
	systems.update<PaddleSystem>(delta);
	systems.update<BallSystem>(delta);
	systems.update<PowerupSystem>(delta);
	systems.update<CollisionSystem>(delta);
	systems.update<PhysicsSystem>(delta);
}

void Level::draw(Renderer * renderer)
{
	entities.each<PhysicsComponent, TileTextureComponent>(
		[renderer](Entity entity, PhysicsComponent & physics, TileTextureComponent & visual)
	{
		renderer->drawTile(physics.position, physics.size, visual.texture);
	});

	auto paddlePhysics = m_paddle.component<PhysicsComponent>();
	auto paddleTexture = m_paddle.component<PaddleTextureComponent>();
	renderer->drawPaddle(paddlePhysics->position, paddlePhysics->size, paddleTexture->texture);

	auto ballPhysics = m_ball.component<PhysicsComponent>();
	auto ballTexture = m_ball.component<BallTextureComponent>();
	renderer->drawBall(ballPhysics->position, ballPhysics->size, ballTexture->texture);
}

void Level::input(char input)
{
	systems.system<InputSystem>()->onInput(input);
}
