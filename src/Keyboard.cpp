#include "Keyboard.h"

Keyboard::Keyboard()
	:
	m_keys(255)
{
	//std::fill_n(m_keys, 255, false);
}

void Keyboard::onKeyPress(char key)
{
	m_keys[key] = true;
}

void Keyboard::onKeyRelease(char key)
{
	m_keys[key] = false;
}

const std::vector<bool> Keyboard::getKeys()
{
	return m_keys;
}
