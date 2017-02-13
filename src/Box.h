#pragma once

#include <memory>

class LifeComponent;
class DropComponent;

class Box
{
public:
	Box();
	~Box();

	void onSpawn(); // flashy animation?
	void onHit();
	void onDestroy();

	std::unique_ptr<LifeComponent> m_life;
	std::unique_ptr<DropComponent> m_drop;
	std::unique_ptr<
};

