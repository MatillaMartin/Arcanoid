#pragma once

#include "ofTexture.h"
#include "Textures.h"
#include "ofImage.h"

class GameTextures
{
public:
	GameTextures();

	const ofTexture & getTexture(TextureId texture);

private:
	std::map<TextureId, ofImage> m_textures;
	ofImage m_notFound;
};