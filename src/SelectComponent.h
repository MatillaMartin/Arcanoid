#pragma once

#include "ofxEntityX.h"

class SelectComponent : public Component<SelectComponent>
{
public:
	SelectComponent(std::vector<Entity> & entityList, double selectDelay);
	
	std::vector<Entity> entityList;
	std::vector<Entity>::iterator selected;

	double selectDelay;
	double delayTimer;
};