#pragma once

#include "ofxEntityX.h"

class PaddleControllerComponent : public Component<PaddleControllerComponent>
{
public:

	struct PaddleParams
	{
		float speed;
	};

	PaddleControllerComponent(const PaddleParams & params = PaddleParams());

	PaddleParams params;

};