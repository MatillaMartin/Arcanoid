#include "TileSystem.h"

#include "HitsComponent.h"
#include "SpriteComponent.h"

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
	events.subscribe<DamageEvent>(*this);
}

void TileSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
}

void TileSystem::receive(const DamageEvent & e)
{
	Entity to = e.to;
	auto type = to.component<TileTypeComponent>();
	auto sprite = to.component<SpriteComponent>();
	auto hits = to.component<HitsComponent>();

	if (hits && type && sprite)
	{
		auto hitCount = hits->getHits();
		auto & textureIds = m_tileMap.find(type->type);
		if (textureIds != m_tileMap.end())
		{
			if (textureIds->second.size() > hitCount)
			{
				TextureId id = textureIds->second[hitCount];
				sprite->texture = id;
			}
		}
	}
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