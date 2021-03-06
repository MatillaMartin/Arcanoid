#include "Level.h"
#include "TileMatrix.h"

#include "PhysicsComponent.h"
#include "HitsComponent.h"

#include "SpriteComponent.h"
#include "TypeComponent.h"

#include "BoxCollisionComponent.h"
#include "CircleCollisionComponent.h"

#include "PaddleControllerComponent.h"
#include "CommandQueueComponent.h"
#include "KeyboardInputComponent.h"

#include "TileSystem.h"
#include "CollisionSystem.h"
#include "PaddleSystem.h"
#include "BallSystem.h"
#include "InputSystem.h"
#include "PowerupSystem.h"
#include "PhysicsSystem.h"


#include "LevelEvents.h"

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
			entity.assign<SpriteComponent>(TextureId::BASIC_0);
			entity.assign<TypeComponent<TileType>>(TileType::BASIC);
			entity.assign<HitsComponent>(1);
			break;
		}
		case TileMatrix::STRONG:
		{
			entity.assign<SpriteComponent>(TextureId::STRONG_1);
			entity.assign<TypeComponent<TileType>>(TileType::STRONG);
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
	PaddleControllerComponent::PaddleParams params;
	params.speed = m_params.paddleSpeed;

	m_paddle = entities.create();
	m_paddle.assign<PhysicsComponent>(paddlePosition, m_visuals.paddleSize, glm::vec2(), glm::vec2(), glm::vec2(m_params.paddleFrictionCoeff, 0.0f));
	m_paddle.assign<BoxCollisionComponent>();
	m_paddle.assign<SpriteComponent>(TextureId::PADDLE);
	m_paddle.assign<KeyboardInputComponent>('a', 'd', 0, 0, ' ');
	m_paddle.assign<CommandQueueComponent>();
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
	m_ball.assign<SpriteComponent>(TextureId::BALL);
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
	// draw all sprites
	entities.each<PhysicsComponent, SpriteComponent>(
		[renderer](Entity entity, PhysicsComponent & physics, SpriteComponent & visual)
	{
		renderer->drawSprite(physics.position, physics.size, visual.texture);
	});
}

void Level::input(char input)
{
	systems.system<InputSystem>()->onInput(input);
}
