#include "TileSystem.h"

#include "HitsComponent.h"
#include "LevelEvents.h"

TileSystem::TileSystem(const std::map<TileType, std::vector<TextureId>> & tileMap, unsigned int tileCount)
	:
	m_tileCount(tileCount),
	m_destroyCount(0),
	m_tileMap(tileMap)
{
}

void TileSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
}

// on block destroyed check if the level is over
//if (m_destroyCount == m_tileCount)
//{
//	events.emit<LevelEndEvent>();
//}


// on collide update the texture given the map!
//if (m_tileMap.find(tile.type) != m_tileMap.end())
//{
//	auto & vec = m_tileMap.at(tile.type);
//	if (hits.getHits() < vec.size())
//	{
//		tile.visual = vec[hits.getHits()];
//	}
//}