#pragma once
#include "ofxEntityX.h"
#include "ofMath.h"

class PositionComponent : public Component<PositionComponent>
{
public:

	PositionComponent(	const glm::vec2 & position = glm::vec2(),
						const glm::vec2 & size = glm::vec2()
	);

	glm::vec2 position;
	glm::vec2 size;

};