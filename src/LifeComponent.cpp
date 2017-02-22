#include "LifeComponent.h"

LifeComponent::LifeComponent(unsigned int health)
	:
	m_health(health),
	bAlive(true)
{
}

void LifeComponent::takeDamage(unsigned int damage)
{
	m_health -= damage;

	bAlive = m_health <= 0; // check if is alive after damage
}

bool LifeComponent::isAlive()
{
	return bAlive;
}