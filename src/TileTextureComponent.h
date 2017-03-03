#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"
#include "Textures.h"
#include "TileType.h"

class TileTextureComponent : public Component<TileTextureComponent>
{
public:
	TileTextureComponent(TileType type, TileTexture visual);

	TileType type;
	TileTexture texture;
};