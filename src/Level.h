#pragma once
#include "ofTexture.h"

#include "ofxEntityX.h"

#include "LevelEndHandler.h"
#include "Renderer.h"
#include "TileType.h"

class TileMatrix;

class Level : public ofxEntityX
{
public:
	class Params
	{
	public:
		std::shared_ptr<TileMatrix> tiles;
		unsigned int time;
		glm::vec2 paddlePosition;
		float paddleSpeed;
		float paddleFrictionCoeff;
	};

	class Visuals
	{
	public:
		// layouts
		ofRectangle levelRegion;
		ofRectangle tileMatrixRegion;

		// relative sizes (tiles already defined by TileMatrix)
		glm::vec2 paddleSize;
		glm::vec2 ballSize;

		// map defining tile transformations
		std::map<TileType, std::vector<TextureId>> tileMap;
	};

	Level(const Params & params, const Visuals & visuals, std::function<void()> onLevelEnd);

	void update(double delta);
	void draw(Renderer * renderer);

	void input(char input);

	Params m_params;
	Visuals m_visuals;

	// no need to look for them if we already have them
	Entity m_paddle;
	Entity m_ball;

	LevelEndHandler m_levelEndHandler;

private:
	void setupEntityX();
	void createTiles();
	void createPaddle();
	void createBall();
};
