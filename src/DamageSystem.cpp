#include "DamageSystem.h"

#include "DamageComponent.h"
#include "HitsComponent.h"
#include "ofLog.h"

DamageSystem::DamageSystem()
{
}

void DamageSystem::configure(EventManager & events)
{
	events.subscribe<CollisionEvent>(*this);
}

void DamageSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
	// remove entities that are dead, GC
	entities.each<HitsComponent>([](Entity e, HitsComponent & hits) 
	{
		if (!hits.isAlive()) // if the entity is not alive
		{
			ofLogVerbose("DamageSystem") << "Destroy the entity";
			e.destroy(); // destroy the entity
		}
	});
}

void DamageSystem::receive(const CollisionEvent & e)
{
	Entity a = e.a;
	Entity b = e.b;

	dealDamage(a, b);
	dealDamage(b, a);
}

void DamageSystem::dealDamage(Entity from, Entity to)
{
	if (from.has_component<DamageComponent>())
	{
		if (to.has_component<HitsComponent>())
		{
			auto hits = to.component<HitsComponent>();
			auto damage = from.component<DamageComponent>();

			ofLogVerbose("DamageSystem") << "Dealing damage " + damage->damage;

			hits->onHit(damage->damage);
		}
	}
}
