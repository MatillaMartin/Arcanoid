#pragma once
#include "ofVec2f.h"

class PositionComponent
{
public:
	PositionComponent(const ofVec2f & initial = ofVec2f());

	ofVec2f position;
};