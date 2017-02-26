#pragma once

#include "ofxEntityX.h"

class TileVisualComponent : public Component<TileVisualComponent>
{
public:
	enum TileVisual { NONE, BASIC, STRONG_1, STRONG_0 };
	TileVisualComponent(TileVisual visual, const glm::vec2 & size);

	virtual void onHit() = 0;

	TileVisual visual;

	glm::vec2 size;
};