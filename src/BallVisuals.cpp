#include "BallVisuals.h"

BallVisuals::BallVisuals(float radius)
	:
	ballSize(radius, radius)
{
	ballQuad.addVertex(ofDefaultVertexType(glm::vec3(0, 0, 0)));
	ballQuad.addVertex(ofDefaultVertexType(glm::vec3(ballSize.x, 0, 0)));
	ballQuad.addVertex(ofDefaultVertexType(glm::vec3(ballSize.x, ballSize.y, 0)));
	ballQuad.addVertex(ofDefaultVertexType(glm::vec3(0, ballSize.y, 0)));

	ballQuad.addTexCoord(ofDefaultTexCoordType(0, 0));
	ballQuad.addTexCoord(ofDefaultTexCoordType(1, 0));
	ballQuad.addTexCoord(ofDefaultTexCoordType(1, 1));
	ballQuad.addTexCoord(ofDefaultTexCoordType(0, 1));

	ballQuad.addIndex(0);
	ballQuad.addIndex(1);
	ballQuad.addIndex(2);
	ballQuad.addIndex(0);
	ballQuad.addIndex(2);
	ballQuad.addIndex(3);

	ballShader.load("shader/BallShader");
}