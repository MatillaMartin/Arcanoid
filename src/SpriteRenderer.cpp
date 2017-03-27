#include "SpriteRenderer.h"
#include "ofGraphics.h"

SpriteRenderer::SpriteRenderer(GameTextures * textures, const glm::vec2 & resolution)
	:
	m_textures(textures),
	m_resolution(resolution)
{
	m_quad.addVertex(ofDefaultVertexType(glm::vec3(0, 0, 0)));
	m_quad.addVertex(ofDefaultVertexType(glm::vec3(1, 0, 0)));
	m_quad.addVertex(ofDefaultVertexType(glm::vec3(1, 1, 0)));
	m_quad.addVertex(ofDefaultVertexType(glm::vec3(0, 1, 0)));

	m_quad.addTexCoord(ofDefaultTexCoordType(0, 0));
	m_quad.addTexCoord(ofDefaultTexCoordType(1, 0));
	m_quad.addTexCoord(ofDefaultTexCoordType(1, 1));
	m_quad.addTexCoord(ofDefaultTexCoordType(0, 1));

	m_quad.addIndex(0);
	m_quad.addIndex(1);
	m_quad.addIndex(2);
	m_quad.addIndex(0);
	m_quad.addIndex(2);
	m_quad.addIndex(3);

	m_shader.load("shader/SpriteShader");
}

void SpriteRenderer::drawSprite(const glm::vec2 & position, const glm::vec2 & size, const ofTexture & texture)
{
	glm::vec2 spritePosition = position * m_resolution;
	glm::vec2 spriteSize = size * m_resolution;

	m_shader.begin();
	m_shader.setUniform2f("pos", spritePosition);
	m_shader.setUniform2f("size", spriteSize);
	m_shader.setUniformTexture("texture", texture, 0);
		m_quad.draw();
	m_shader.end();
}

void SpriteRenderer::drawSprite(const glm::vec2 & position, const glm::vec2 & size, TextureId tex)
{
	drawSprite(position, size, m_textures->getTexture(tex));
}