#pragma once

#include "ofImage.h"

class TileMatrix
{
public:
	enum TileType { EMPTY, BASIC, STRONG };

	TileMatrix(const ofImage & descriptor);

	vector<TileType> matrix;
	unsigned int nCols;
	unsigned int nRows;

	unsigned int count();

private:
	const static ofColor s_EmptyColor;
	const static ofColor s_BasicColor;
	const static ofColor s_StrongColor;
};