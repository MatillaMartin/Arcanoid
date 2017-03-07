#pragma once

#include "ofxEntityX.h"
#include "Textures.h"
#include "ofColor.h"

class SpriteComponent : public Component<SpriteComponent>
{
public:
	SpriteComponent(TextureId texture);
	
	TextureId texture;
};