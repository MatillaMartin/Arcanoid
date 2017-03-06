#include "Keyboard.h"
#include "ofEvent.h"

Keyboard::Keyboard()
{
	ofAddListener(ofEvents().keyPressed, this, &Keyboard::onKeyPress);
	ofAddListener(ofEvents().keyReleased, this, &Keyboard::onKeyRelease);
}

void Keyboard::onKeyPress(ofKeyEventArgs & key)
{
	m_keys[(char)key.key] = true;
}

void Keyboard::onKeyRelease(ofKeyEventArgs & key)
{
	m_keys[(char)key.key] = false;
}

const std::map<char, bool> & Keyboard::getKeys()
{
	return m_keys;
}
