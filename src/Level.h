#pragma once
#include "ofTexture.h"

#include "ofxEntityX.h"

#include "TileTexture.h"
#include "TileVisuals.h"
#include "PaddleVisuals.h"
#include "BallVisuals.h"

#include "LevelEndHandler.h"

class TileMatrix;

class Level : public ofxEntityX
{
public:
	class LevelParams
	{
	public:
		std::shared_ptr<TileMatrix> tiles;
		unsigned int time;
		glm::vec2 paddlePosition;
	};

	class LevelVisuals
	{
	public:
		// layouts
		ofRectangle levelRegion;
		ofRectangle tileMatrixRegion;

		// relative sizes (tiles already defined by TileMatrix)
		glm::vec2 paddleSize;
		float ballRadius;

		// textures
		map<TileTexture, ofTexture> tileTextures;
		ofTexture paddleTexture;
		ofTexture ballTexture;
	};

	Level(const LevelParams & params, const LevelVisuals & visuals, LevelEndHandler * handler);


	void update(double delta);
	void draw();

	LevelParams m_params;
	LevelVisuals m_visuals;

	TileVisuals m_tileVisuals;
	PaddleVisuals m_paddleVisuals;
	BallVisuals m_ballVisuals;
	// no need to look for them if we already have them
	Entity m_paddle;
	Entity m_ball;

	LevelEndHandler * m_levelEndHandler;

private:
	void setupEntityX();
	void createTiles();
	void createPaddle();
	void createBall();
};
