#pragma once
#include "HitInfo.h"
#include "ofxEntityX.h"

class Tile;

class TileSystem : public System<TileSystem>
{
	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;
};