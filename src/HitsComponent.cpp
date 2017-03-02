#include "HitsComponent.h"

#include "ofMath.h"

HitsComponent::HitsComponent(unsigned int maxHits)
	:
	m_maxHits(maxHits),
	m_hits(0),
	bAlive(true)
{
}

unsigned int HitsComponent::getHits()
{
	return m_hits;
}

void HitsComponent::onHit(unsigned int hit)
{
	m_hits += hit;

	//clamp to max hits
	m_hits = MIN(m_hits, m_maxHits);

	bAlive = m_hits < m_maxHits; // check if is alive after hit
}

bool HitsComponent::isAlive()
{
	return bAlive;
}