#pragma once

class HitsComponent
{
public:
	HitsComponent(unsigned int maxHits);

	unsigned int getHits();
	void onHit(unsigned int damage);
	bool isAlive();

private:
	unsigned int m_maxHits;
	unsigned int m_hits;
	bool bAlive;
};