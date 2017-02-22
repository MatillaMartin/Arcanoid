#pragma once

#include "ofTexture.h"

class VisualComponent
{
public:
	VisualComponent(const vector<ofTexture *> & texture);

	vector<ofTexture *> m_texture;
};