#include "GameTextures.h"

GameTextures::GameTextures()
{
	m_notFound.allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);

	m_textures[TextureId::NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);
	m_textures[TextureId::BASIC_0].load("basicTile.png");
	m_textures[TextureId::STRONG_0].load("strongTile_0.png");
	m_textures[TextureId::STRONG_1].load("strongTile_1.png");
	
	m_textures[TextureId::PADDLE].load("paddle.png");
	m_textures[TextureId::BALL].load("ball.png");
			   
	m_textures[TextureId::LEVEL_0].load("level_background.png");
	
	m_textures[TextureId::NONE].allocate(1, 1, ofImageType::OF_IMAGE_COLOR_ALPHA);
	m_textures[TextureId::PLAY].load("play.png");
	m_textures[TextureId::PLAY_SEL].load("play_sel.png");
	m_textures[TextureId::CREDITS].load("credits.png");
	m_textures[TextureId::CREDITS_SEL].load("credits_sel.png");
	m_textures[TextureId::EXIT].load("exit.png");
	m_textures[TextureId::EXIT_SEL].load("exit_sel.png");
}

const ofTexture & GameTextures::getTexture(TextureId texture)
{
	if(m_textures.find(texture) != m_textures.end())
	{
		return m_textures.at(texture).getTexture();
	}
	return m_notFound.getTexture();
}