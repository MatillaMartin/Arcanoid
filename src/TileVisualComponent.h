#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"
#include "Textures.h"
#include "TileType.h"

class TileVisualComponent : public Component<TileVisualComponent>
{
public:
	TileVisualComponent(TileTexture visual, const glm::vec2 & size);

	TileType type;
	TileTexture visual;
	glm::vec2 size;
};