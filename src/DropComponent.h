#pragma once

#include "ofxEntityX.h"

class DropComponent : public Component<DropComponent>
{
public:
	enum DropType { NONE, STICK, SHOT /*...*/ };

	DropComponent(DropType type = NONE);
	
	DropType m_type;
};