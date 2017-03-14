#pragma once

#include "ofxEntityX.h"

class ShootComponent : public Component<ShootComponent>
{
public:
	class ShootableComponent : public Component<ShootableComponent> {};

	ShootComponent(float period, float speed);

	float period;
	float currentTime;
	float speed;
};