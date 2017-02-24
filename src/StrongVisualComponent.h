#pragma once

#include "ofxEntityX.h"
#include "ofMath.h"
#include "TileVisualComponent.h"

class StrongVisualComponent : public Component<StrongVisualComponent>, public TileVisualComponent
{
	StrongVisualComponent();

	void onHit() override;
};