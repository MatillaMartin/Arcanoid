#include "StickComponent.h"

StickComponent::StickComponent(Entity who, float maxStickTime, float releaseSpeed)
	:
	who(who),
	maxStickTime(maxStickTime),
	currentStickTime(0.0f),
	releaseSpeed(releaseSpeed)
{}