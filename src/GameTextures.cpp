#include "GameTextures.h"

GameTextures::GameTextures()
{
	notFound.allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);

	textures[NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);
	textures[BASIC_0].load("basicTile.png");
	textures[STRONG_0].load("strongTile_0.png");
	textures[STRONG_1].load("strongTile_1.png");
	
	textures[PADDLE].load("paddle.png");
	textures[BALL].load("ball.png");

	textures[LEVEL_0].load("level_background.png");

	textures[NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);
	textures[PLAY].load("play.png");
	textures[PLAY_SEL].load("play_sel.png");
	textures[CREDITS].load("credits.png");
	textures[CREDITS_SEL].load("credits_sel.png");
	textures[EXIT].load("exit.png");
	textures[EXIT_SEL].load("exit_sel.png");
}

const ofTexture & GameTextures::getTexture(TextureId texture)
{
	if(textures.find(texture) != textures.end())
	{
		return textures.at(texture).getTexture();
	}
	return notFound.getTexture();
}