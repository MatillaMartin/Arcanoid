#include "StickComponent.h"

StickComponent::StickComponent(Entity stickable, float maxStickTime, float releaseSpeed)
	:
	stickable(stickable),
	maxStickTime(maxStickTime),
	currentStickTime(0.0f),
	releaseSpeed(releaseSpeed)
{}