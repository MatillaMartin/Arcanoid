#pragma once

#include <vector>

class Keyboard
{
public:
	Keyboard();
	void onKeyPress(char key);
	void onKeyRelease(char key);

	const std::vector<bool> getKeys();

	std::vector<bool> m_keys;
};