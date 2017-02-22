#pragma once

class LifeComponent
{
public:
	LifeComponent(unsigned int health);

	void takeDamage(unsigned int damage);
	bool isAlive();

private:
	unsigned int m_health;
	bool bAlive;
};