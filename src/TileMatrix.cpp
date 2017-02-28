#include "TileMatrix.h"


TileMatrix::TileMatrix(const ofImage & descriptor)
	:
	matrixWidth(descriptor.getWidth()),
	matrixHeight(descriptor.getHeight())
{
	const static ofColor emptyColor = ofColor::black;
	const static ofColor basicColor = ofColor::white;
	const static ofColor strongColor = ofColor::blue;

	unsigned int size = matrixWidth*matrixHeight;
	matrix.reserve(size);

	for (unsigned int y = 0; y < matrixHeight; y++)
	{
		for (unsigned int x = 0; x < matrixWidth; x++)
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
	return matrixWidth * matrixHeight;
}
