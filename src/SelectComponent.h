#pragma once

#include "ofxEntityX.h"

class SelectComponent : public Component<SelectComponent>
{
public:
	SelectComponent(std::vector<Entity> & entityList);
	
	std::vector<Entity> m_entityList;
	std::vector<Entity>::iterator m_selected;
};