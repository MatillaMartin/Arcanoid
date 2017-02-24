#pragma once

#include "ofxEntityX.h"
#include "TileVisualComponent.h"

class BasicVisualComponent : public Component<BasicVisualComponent>, public TileVisualComponent
{
	BasicVisualComponent();

	void onHit() override;
};