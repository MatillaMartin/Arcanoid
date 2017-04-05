#include "TileSystem.h"

#include "HitsComponent.h"
#include "LevelEvents.h"
#include "DamageComponent.h"

TileSystem::TileSystem(EventManager * events, const std::map<TileType, std::vector<TextureId>> & tileMap, unsigned int tileCount)
	:
	m_events(events),
	m_tileCount(tileCount),
	m_destroyCount(0),
	m_tileMap(tileMap)
{
}

void TileSystem::configure(EventManager & events)
{
	events.subscribe<EntityDestroyedEvent>(*this);
}

void TileSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
}

void TileSystem::receive(const EntityDestroyedEvent & e)
{
	if (e.entity.has_component<TileTypeComponent>())
	{
		m_destroyCount++;

		if (m_destroyCount == m_tileCount)
		{
			m_events->emit<LevelEndEvent>();
		}
	}
}