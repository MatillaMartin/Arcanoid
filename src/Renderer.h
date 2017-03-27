#pragma once

#include "Textures.h"
#include "ofMath.h"

class Renderer
{
public:
	virtual void drawSprite(const glm::vec2 & position, const glm::vec2 & size, TextureId tex) = 0;
	virtual void drawSpriteCentered(const glm::vec2 & center, const glm::vec2 & size, TextureId tex)
	{
		// position is sprite centered
		glm::vec2 position = center - size / 2.0f;
		drawSprite(position, size, tex);
	}
};