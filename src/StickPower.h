#pragma once

#include "StickComponent.h"
#include "PowerEvents.h"

class UseStickEventHandler : public Receiver<UseStickEvent>
{
public:
	void receive(const UseStickEvent & e);
};


class StickCollisionHandler : public Receiver<StickCollision>
{
public:
	StickCollisionHandler(float maxStickTime, float releaseSpeed);

	void receive(const StickCollision & e);

	float maxStickTime;
	float releaseSpeed;
};