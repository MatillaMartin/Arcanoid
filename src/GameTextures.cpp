#include "GameTextures.h"

GameTextures::GameTextures()
{
	notFound.allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);

	tiles[TileTexture::NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);
	tiles[TileTexture::BASIC_0].load("basicTile.png");
	tiles[TileTexture::STRONG_0].load("strongTile_0.png");
	tiles[TileTexture::STRONG_1].load("strongTile_1.png");
	
	paddle[PaddleTexture::PADDLE].load("paddle.png");
	ball[BallTexture::BALL].load("ball.png");
}

const ofTexture & GameTextures::getTexture(TileTexture texture)
{
	if(tiles.find(texture) != tiles.end())
	{
		return tiles.at(texture).getTexture();
	}
	return notFound.getTexture();
}

const ofTexture & GameTextures::getTexture(PaddleTexture texture)
{
	if (paddle.find(texture) != paddle.end())
	{
		return paddle.at(texture).getTexture();
	}
	return notFound.getTexture();
}

const ofTexture & GameTextures::getTexture(BallTexture texture)
{
	if (ball.find(texture) != ball.end())
	{
		return ball.at(texture).getTexture();
	}
	return notFound.getTexture();
}