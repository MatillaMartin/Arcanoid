#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"

class TileVisualComponent : public Component<TileVisualComponent>
{
public:
	enum TileVisual { NONE, BASIC, STRONG_1, STRONG_0 };
	TileVisualComponent(TileVisual visual, const glm::vec2 & size);

	TileVisual visual;
	glm::vec2 size;
};