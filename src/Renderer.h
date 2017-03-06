#pragma once

#include "Textures.h"
#include "ofMath.h"

class Renderer
{
public:
	virtual void drawTile(const glm::vec2 & position, const glm::vec2 & size, TileTexture tex) = 0;
	virtual void drawBall(const glm::vec2 & position, const glm::vec2 & size, BallTexture tex) = 0;
	virtual void drawPaddle(const glm::vec2 & position, const glm::vec2 & size, PaddleTexture tex) = 0;
	virtual void drawBackground(LevelTexture tex) = 0;
};