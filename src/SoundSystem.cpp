#include "SoundSystem.h"
#include "CollisionEvent.h"

SoundSystem::SoundSystem(SoundPlayer * player)
	:
	m_soundPlayer(player)
{
}

void SoundSystem::configure(EventManager & events)
{
	events.subscribe<CollisionEvent>(*this);
}

void SoundSystem::update(EntityManager & entities, EventManager & events, TimeDelta dt)
{
}

void SoundSystem::receive(const CollisionEvent & e)
{
	Entity a = e.a;
	Entity b = e.b;

	auto aSound = a.component<SoundTypeComponent>();
	auto bSound = b.component<SoundTypeComponent>();

	auto checkTypes = [aSound, bSound](SoundType onetype, SoundType othertype) -> bool
	{
		return (aSound->type == onetype && bSound->type == othertype) || (aSound->type == othertype && bSound->type == onetype);
	};

	if (aSound && bSound)
	{
		if (checkTypes(SoundType::BALL, SoundType::PADDLE))
		{
			m_soundPlayer->playSound(SoundId::BALL_0);
		}

		if (checkTypes(SoundType::BALL, SoundType::TILE))
		{
			m_soundPlayer->playSound(SoundId::BALL_2);
		}
	}
}