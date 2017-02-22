#include "TileMatrix.h"

const ofColor TileMatrix::s_EmptyColor = ofColor::black;
const ofColor TileMatrix::s_BasicColor = ofColor::white;
const ofColor TileMatrix::s_StrongColor = ofColor::blue;

TileMatrix::TileMatrix(const ofImage & descriptor)
	:
	matrixWidth(descriptor.getWidth()),
	matrixHeight(descriptor.getHeight())
{
	matrix.reserve(descriptor.getPixels().size());
	for (unsigned int i = 0; i < descriptor.getPixels().size(); i++)
	{
		ofColor color = descriptor.getColor(i);

		if (color == s_EmptyColor)
		{
			matrix.push_back(TileType::EMPTY); continue;
		}
		if (color == s_BasicColor)
		{
			matrix.push_back(TileType::BASIC); continue;
		}
		if (color == s_StrongColor)
		{
			matrix.push_back(TileType::STRONG); continue;
		}
	}
}
