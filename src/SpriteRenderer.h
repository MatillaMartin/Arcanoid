#pragma once

#include "ofMath.h"
#include "Renderer.h"
#include "ofShader.h"
#include "ofVboMesh.h"
#include "GameTextures.h"

class SpriteRenderer : public Renderer
{
public:
	SpriteRenderer(GameTextures * textures, const glm::vec2 & resolution);

	void drawSprite(const glm::vec2 & position, const glm::vec2 & size, const ofTexture & texture);

	void drawTile(const glm::vec2 & position, const glm::vec2 & size, TileTexture tex) override;
	void drawBall(const glm::vec2 & position, const glm::vec2 & size, BallTexture tex) override;
	void drawPaddle(const glm::vec2 & position, const glm::vec2 & size, PaddleTexture tex) override;

private:
	ofShader m_shader;
	ofVboMesh m_quad;
	GameTextures * m_textures;
	glm::vec2 m_resolution;
};
