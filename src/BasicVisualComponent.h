#pragma once

#include "ofxEntityX.h"

class BasicVisualComponent : public Component<BasicVisualComponent>
{
	BasicVisualComponent(double width, double height);

	double width;
	double height;

	// texture is assigned in the system, as the texture is constant for all components
};