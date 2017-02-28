#pragma once

#include "ofVboMesh.h"
#include "ofShader.h"

class BallVisuals
{
public:
	BallVisuals(float radius);

	float ballSize;
	ofVboMesh ballQuad;
	ofShader ballShader;
};