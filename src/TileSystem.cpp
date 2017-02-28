#include "TileSystem.h"

#include "LifeComponent.h"
#include "TileVisualComponent.h"
#include "BoxCollisionComponent.h"
#include "Events.h"

TileSystem::TileSystem(unsigned int tileCount)
	:
	m_tileCount(tileCount),
	m_destroyCount(0)
{
}

void TileSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	if (m_destroyCount == m_tileCount)
	{
		events.emit<LevelEndEvent>();
	}
}