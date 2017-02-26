#pragma once

#include "ofxEntityX.h"

class PlayerVisualComponent : public Component<PlayerVisualComponent>
{
public:
	PlayerVisualComponent(const glm::vec2 & size);
	glm::vec2 size;
};