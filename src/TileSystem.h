#pragma once
#include "HitInfo.h"
#include "ofxEntityX.h"
#include "TileType.h"
#include "Textures.h"
#include <map>
#include <vector>

class TileSystem : public System<TileSystem>
{
public:
	TileSystem(const std::map<TileType, std::vector<TileTexture>> & tileMap, unsigned int tileCount);

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

private:
	unsigned int m_tileCount;
	unsigned int m_destroyCount;
	std::map<TileType, std::vector<TileTexture>> m_tileMap;
};