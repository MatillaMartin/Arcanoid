#include "PaddleVisuals.h"

PaddleVisuals::PaddleVisuals(float width, float height)
	:
	paddleSize(width, height)
{
	paddleQuad.addVertex(ofDefaultVertexType(glm::vec3(0, 0, 0)));
	paddleQuad.addVertex(ofDefaultVertexType(glm::vec3(paddleSize.x, 0, 0)));
	paddleQuad.addVertex(ofDefaultVertexType(glm::vec3(paddleSize.x, paddleSize.y, 0)));
	paddleQuad.addVertex(ofDefaultVertexType(glm::vec3(0, paddleSize.y, 0)));

	paddleQuad.addTexCoord(ofDefaultTexCoordType(0, 0));
	paddleQuad.addTexCoord(ofDefaultTexCoordType(1, 0));
	paddleQuad.addTexCoord(ofDefaultTexCoordType(1, 1));
	paddleQuad.addTexCoord(ofDefaultTexCoordType(0, 1));

	paddleQuad.addIndex(0);
	paddleQuad.addIndex(1);
	paddleQuad.addIndex(2);
	paddleQuad.addIndex(0);
	paddleQuad.addIndex(2);
	paddleQuad.addIndex(3);

	paddleShader.load("shader/PaddleShader");
}
