#pragma once

class TileVisualComponent
{
public:
	enum TileVisual { NONE, BASIC, STRONG_1, STRONG_0 };
	TileVisualComponent(TileVisual visual);

	virtual void onHit() = 0;

	TileVisual visual;
};