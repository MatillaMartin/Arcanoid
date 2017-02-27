#pragma once

#include "ofxEntityX.h"

class PaddleController : public Component<PaddleController>
{
public:
	struct PaddleParams
	{
		float speed;
		float friction;
	};

	PaddleController(const PaddleParams & params);

	PaddleParams params;
};