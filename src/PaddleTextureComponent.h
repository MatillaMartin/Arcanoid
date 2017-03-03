#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"
#include "Textures.h"

class PaddleTextureComponent : public Component<PaddleTextureComponent>
{
public:
	PaddleTextureComponent(PaddleTexture texture);

	PaddleTexture texture;
};