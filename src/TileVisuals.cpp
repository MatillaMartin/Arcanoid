#include "TileVisuals.h"

TileVisuals::TileVisuals(const ofRectangle & tileMatrixRegion, float nTilesWidth, float nTilesHeight)
	:
	tileSize(tileMatrixRegion.width / nTilesWidth, tileMatrixRegion.height / nTilesHeight)
{
	
}
