#include "TileVisuals.h"

TileVisuals::TileVisuals(const ofRectangle & tileMatrixRegion, float nTilesWidth, float nTilesHeight)
	:
	tileSize(tileMatrixRegion.width / nTilesWidth, tileMatrixRegion.height / nTilesHeight)
{
	tileQuad.addVertex(ofDefaultVertexType(glm::vec3(0, 0, 0)));
	tileQuad.addVertex(ofDefaultVertexType(glm::vec3(tileSize.x, 0, 0)));
	tileQuad.addVertex(ofDefaultVertexType(glm::vec3(tileSize.x, tileSize.y, 0)));
	tileQuad.addVertex(ofDefaultVertexType(glm::vec3(0, tileSize.y, 0)));

	tileQuad.addTexCoord(ofDefaultTexCoordType(glm::vec3(0, 0, 0)));
	tileQuad.addTexCoord(ofDefaultTexCoordType(glm::vec3(1, 0, 0)));
	tileQuad.addTexCoord(ofDefaultTexCoordType(glm::vec3(1, 1, 0)));
	tileQuad.addTexCoord(ofDefaultTexCoordType(glm::vec3(0, 1, 0)));

	tileQuad.addIndex(0);
	tileQuad.addIndex(1);
	tileQuad.addIndex(2);
	tileQuad.addIndex(0);
	tileQuad.addIndex(2);
	tileQuad.addIndex(3);

	tileShader.load("shader/TileShader");
}
