#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"
#include "TileTexture.h"

class TileVisualComponent : public Component<TileVisualComponent>
{
public:
	TileVisualComponent(TileTexture visual, const glm::vec2 & size);

	TileTexture visual;
	glm::vec2 size;
};