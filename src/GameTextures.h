#pragma once

#include "ofTexture.h"
#include "Textures.h"
#include "ofImage.h"

class GameTextures
{
public:
	GameTextures();

	const ofTexture & getTexture(TileTexture texture);
	const ofTexture & getTexture(PaddleTexture texture);
	const ofTexture & getTexture(BallTexture texture);
	const ofTexture & getTexture(LevelTexture texture);
private:
	std::map<TileTexture, ofImage> tiles;
	std::map<PaddleTexture, ofImage> paddle;
	std::map<BallTexture, ofImage> ball;
	std::map<LevelTexture, ofImage> level;

	ofImage notFound;
};