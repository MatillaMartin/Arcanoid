#pragma once
#include "Renderer.h"

class Screen
{
	virtual void update(double delta) = 0;
	virtual void draw(Renderer * renderer) = 0;
	virtual void input(char input) = 0;
};