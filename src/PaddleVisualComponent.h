#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"

class PaddleVisualComponent : public Component<PaddleVisualComponent>
{
public:
	PaddleVisualComponent(const glm::vec2 & size);
	glm::vec2 size;
};