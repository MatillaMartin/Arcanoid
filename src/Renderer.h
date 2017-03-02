#pragma once

#include "Textures.h"
#include "ofMath.h"

class Renderer
{
	virtual void drawTile(const glm::vec2 & position, TileTexture tex) = 0;
	virtual void drawBall(const glm::vec2 & position, BallTexture tex) = 0;
	virtual void drawPaddle(const glm::vec2 & position, PaddleTexture tex) = 0;
};

class SpriteRenderer : public Renderer
{

};

class CollisionRenderer : public Renderer
{

};