#pragma once

#include "ofVboMesh.h"
#include "ofShader.h"

class BallVisuals
{
public:
	BallVisuals(float radius);

	glm::vec2 ballSize;
	ofVboMesh ballQuad;
	ofShader ballShader;
};