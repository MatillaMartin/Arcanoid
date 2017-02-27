#pragma once

#include "ofVboMesh.h"
#include "ofShader.h"

class PaddleVisuals
{
public:
	PaddleVisuals(float width, float height);

	glm::vec2 paddleSize;
	ofVboMesh paddleQuad;
	ofShader paddleShader;
};