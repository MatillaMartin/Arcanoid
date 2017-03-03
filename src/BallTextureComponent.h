#pragma once
#include "ofxEntityX.h"
#include "Textures.h"

class BallTextureComponent : Component<BallTextureComponent>
{
public:
	BallTextureComponent(BallTexture texture);

	BallTexture texture;
};