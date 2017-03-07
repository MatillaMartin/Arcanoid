#pragma once

#include "Textures.h"
#include "ofMath.h"

class Renderer
{
public:
	virtual void drawSprite(const glm::vec2 & position, const glm::vec2 & size, TextureId tex) = 0;

};