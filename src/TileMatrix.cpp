#include "TileMatrix.h"


TileMatrix::TileMatrix(const ofImage & descriptor)
	:
	nCols(descriptor.getWidth()),
	nRows(descriptor.getHeight())
{
	const static ofColor emptyColor = ofColor::black;
	const static ofColor basicColor = ofColor::white;
	const static ofColor strongColor = ofColor::blue;

	unsigned int size = nCols*nRows;
	matrix.reserve(size);

	for (unsigned int y = 0; y < nRows; y++)
	{
		for (unsigned int x = 0; x < nCols; x++)
		{
			ofColor color = descriptor.getColor(x, y);

			if (color == emptyColor)
			{
				matrix.push_back(TileType::EMPTY); continue;
			}
			if (color == basicColor)
			{
				matrix.push_back(TileType::BASIC); continue;
			}
			if (color == strongColor)
			{
				matrix.push_back(TileType::STRONG); continue;
			}
		}
	}
}

unsigned int TileMatrix::count()
{
	return nCols * nRows;
}
