#pragma once
#include "Renderer.h"

class Screen
{
	virtual void update(float delta) = 0;
	virtual void draw(Renderer * renderer) = 0;
};