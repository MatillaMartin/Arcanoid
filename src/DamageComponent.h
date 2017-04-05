#pragma once

#include "ofxEntityX.h"

class DamageComponent : public Component<DamageComponent>
{
public:
	DamageComponent(unsigned int damage);
	
	unsigned int damage;
};