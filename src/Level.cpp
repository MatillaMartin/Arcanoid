#include "Level.h"
#include "TileMatrix.h"

#include "PhysicsComponent.h"
#include "PositionComponent.h"
#include "HitsComponent.h"

#include "SpriteComponent.h"
#include "TypeComponent.h"

#include "PaddleControllerComponent.h"
#include "CommandQueueComponent.h"
#include "KeyboardInputComponent.h"

#include "TileSystem.h"
#include "CollisionSystem.h"
#include "PaddleSystem.h"
#include "BallSystem.h"
#include "InputSystem.h"
#include "PowerSystem.h"
#include "PhysicsSystem.h"

#include "StickComponent.h"

#include "LevelEvents.h"

#include "ofGraphics.h"

#define PHYSICS_SCALE 1024

Level::Level(const Params & params, const Visuals & visuals, std::function<void()> onLevelEnd)
	:
	m_params(params),
	m_visuals(visuals),
	m_levelEndHandler(onLevelEnd)
{
	setupBox2d();
	setupEntityX();
	createTiles();
	createPaddle();
	createBall();
	createBounds();

	onLevelStart();
}

Level::~Level()
{
	// remove ofxBox2d components before destroying ofxBox2d
	entities.each<PhysicsComponent>([](Entity & e, PhysicsComponent & physics)
	{
		e.remove<PhysicsComponent>();
	});
}

void Level::setupBox2d()
{
	// scale up level
	m_visuals.levelRegion.scale(PHYSICS_SCALE);
	m_visuals.tileMatrixRegion = m_visuals.levelRegion.map(m_visuals.tileMatrixRegion);
	m_visuals.paddleSize = m_visuals.levelRegion.map(m_visuals.paddleSize);
	m_visuals.ballSize = m_visuals.levelRegion.map(m_visuals.ballSize);

	m_params.ballSpeed *= PHYSICS_SCALE;
	m_params.paddleSpeed *= PHYSICS_SCALE;

	m_box2d.init();
	m_box2d.setGravity(0, 0);
	m_box2d.setFPS(60.0);
}

void Level::setupEntityX()
{
	systems.add<InputSystem>();
	systems.add<TileSystem>(m_visuals.tileMap, m_params.tiles->count());
	systems.add<CollisionSystem>(&m_box2d);
	systems.add<PaddleSystem>();
	systems.add<BallSystem>();
	systems.add<PowerSystem>();
	systems.add<PhysicsSystem>();
	systems.configure();

	this->events.subscribe<LevelEndEvent>(m_levelEndHandler);
}

void Level::createTiles()
{
	// determine tile size from region
	glm::vec2 tileSize (m_visuals.tileMatrixRegion.width / m_params.tiles->nCols, 
						m_visuals.tileMatrixRegion.height / m_params.tiles->nRows);

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
		tilePosition += tileSize / 2.0f;

		entityx::Entity entity = entities.create();
		// common values for all tiles
		entity.assign<PositionComponent>(tilePosition, tileSize);
		entity.assign<PhysicsComponent>(
			PhysicsInfo(),
			BoxCollision(tilePosition, tileSize), 
			CollisionInfo(false, b2BodyType::b2_staticBody),
			m_box2d.getWorld()
		);

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
	m_paddle.assign<PositionComponent>(paddlePosition, m_visuals.paddleSize);
	m_paddle.assign<PhysicsComponent>
	(
		PhysicsInfo(glm::vec2(), glm::vec2(), glm::vec2(m_params.paddleFrictionCoeff, 0.0f)), 
		BoxCollision(paddlePosition, m_visuals.paddleSize), 
		CollisionInfo(false, b2BodyType::b2_kinematicBody),
		m_box2d.getWorld()
	);

	m_paddle.assign<SpriteComponent>(TextureId::PADDLE);
	m_paddle.assign<KeyboardInputComponent>('a', 'd', 0, 0, ' ');
	m_paddle.assign<CommandQueueComponent>();
	m_paddle.assign<PaddleControllerComponent>(params);
}

void Level::createBall()
{
	// find initial location relative to the paddle
	ComponentHandle<PositionComponent> paddle = m_paddle.component<PositionComponent>();
	glm::vec2 ballPosition = paddle->position; // centered
	ballPosition.y -= m_visuals.ballSize.y;

	m_ball = entities.create();
	m_ball.assign<PositionComponent>(ballPosition, m_visuals.ballSize);
	m_ball.assign<PhysicsComponent>
	(
		PhysicsInfo(),
		CircleCollision(ballPosition, m_visuals.ballSize.x / 2.0f),
		CollisionInfo(true, b2BodyType::b2_dynamicBody),
		m_box2d.getWorld()
	);
	m_ball.assign<SpriteComponent>(TextureId::BALL);
}

void Level::createBounds()
{
	// also creats lower bound
	//box2d.createBounds(0, 0, 1, 1);
	auto leftBound = entities.create();
	leftBound.assign<PhysicsComponent>
	(
		PhysicsInfo(),
		EdgeCollision(glm::vec2(m_visuals.levelRegion.getTopLeft()), glm::vec2(m_visuals.levelRegion.getBottomLeft())),
		CollisionInfo(false, b2BodyType::b2_staticBody),
		m_box2d.getWorld()
	);

	auto rightBound = entities.create();
	rightBound.assign<PhysicsComponent>
	(
		PhysicsInfo(),
		EdgeCollision(glm::vec2(m_visuals.levelRegion.getTopRight()), glm::vec2(m_visuals.levelRegion.getBottomRight())),
		CollisionInfo(false, b2BodyType::b2_staticBody),
		m_box2d.getWorld()
	);
	auto topBound = entities.create();
	topBound.assign<PhysicsComponent>
	(
		PhysicsInfo(),
		EdgeCollision(glm::vec2(m_visuals.levelRegion.getTopLeft()), glm::vec2(m_visuals.levelRegion.getTopRight())),
		CollisionInfo(false, b2BodyType::b2_staticBody),
		m_box2d.getWorld()
	);
}


void Level::update(double delta)
{
	systems.update<InputSystem>(delta);
	systems.update<TileSystem>(delta);
	systems.update<PaddleSystem>(delta);
	systems.update<BallSystem>(delta);
	systems.update<PowerSystem>(delta);
	systems.update<CollisionSystem>(delta);
	systems.update<PhysicsSystem>(delta);
}

void Level::draw(Renderer * renderer)
{
	// draw all sprites
	entities.each<PositionComponent, SpriteComponent>(
		[renderer](Entity entity, PositionComponent & position, SpriteComponent & visual)
	{
		renderer->drawSpriteCentered(position.position / PHYSICS_SCALE, position.size / PHYSICS_SCALE, visual.texture);
	});

	//entities.each<PhysicsComponent, PositionComponent, SpriteComponent>(
	//	[renderer](Entity entity, PhysicsComponent & physics, PositionComponent & position, SpriteComponent & visual)
	//{
	//	physics.collision->draw();
	//});
}

void Level::input(char input)
{
	systems.system<InputSystem>()->onInput(input);
}

void Level::onLevelStart()
{
	events.subscribe<UseStickEvent>(m_powerEvents.m_stickHandler);
	m_paddle.assign<TypeComponent<PowerType>>(PowerType::STICK);
	m_paddle.assign<StickComponent>(m_ball, m_params.paddleStickTime, m_params.ballSpeed);
}