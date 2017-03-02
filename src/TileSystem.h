#pragma once
#include "HitInfo.h"
#include "ofxEntityX.h"

class Tile;

class TileSystem : public System<TileSystem>
{
public:
	TileSystem(const map<TileType, std::vector<TileTexture>> & tileMap, unsigned int tileCount);

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

private:
	unsigned int m_tileCount;
	unsigned int m_destroyCount;
	map<TileType, std::vector<TileTexture>> m_tileMap;
};