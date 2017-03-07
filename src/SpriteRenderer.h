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

	// Inherited via Renderer
	virtual void drawSprite(const glm::vec2 & position, const glm::vec2 & size, TextureId tex) override;
private:
	void drawSprite(const glm::vec2 & position, const glm::vec2 & size, const ofTexture & texture);

	ofShader m_shader;
	ofVboMesh m_quad;
	GameTextures * m_textures;
	glm::vec2 m_resolution;

	
};
