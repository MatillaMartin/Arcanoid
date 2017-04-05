#pragma once
#include "HitInfo.h"
#include "ofxEntityX.h"
#include "TileType.h"
#include "Textures.h"
#include <map>
#include <vector>
#include "CollisionEvent.h"
#include "TypeComponent.h"

class TileSystem : public System<TileSystem>, public Receiver<TileSystem>
{
public:
	typedef TypeComponent<TileType> TileTypeComponent;

	TileSystem(EventManager * events, const std::map<TileType, std::vector<TextureId>> & tileMap, unsigned int tileCount);

	void configure(EventManager & events) override;

	// Inherited via System
	virtual void update(EntityManager & entities, EventManager & events, TimeDelta dt) override;

	void receive(const EntityDestroyedEvent & e);

private:
	unsigned int m_tileCount;
	unsigned int m_destroyCount;
	std::map<TileType, std::vector<TextureId>> m_tileMap;

	EventManager * m_events;
};