#pragma once

#include "ofxEntityX.h"
#include "MenuEvents.h"

class UseComponent : public Component<UseComponent>
{
public:
	UseComponent(MenuItem item);

	MenuItem item;
};