#pragma once

#include "ofxEntityX.h"

class StrongVisualComponent : public Component<StrongVisualComponent>
{
	StrongVisualComponent(double width, double heigth);

	double width;
	double height;

	// texture is assigned in the system, as the texture is constant for all components
};