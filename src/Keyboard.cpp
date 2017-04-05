#include "Keyboard.h"
#include "ofEvent.h"

Keyboard::Keyboard(const std::set<char> & filter)
{
	setFilter(filter);

	ofAddListener(ofEvents().keyPressed, this, &Keyboard::onKeyPress);
	ofAddListener(ofEvents().keyReleased, this, &Keyboard::onKeyRelease);
}

Keyboard::~Keyboard()
{
	ofRemoveListener(ofEvents().keyPressed, this, &Keyboard::onKeyPress);
	ofRemoveListener(ofEvents().keyReleased, this, &Keyboard::onKeyRelease);
}

void Keyboard::onKeyPress(ofKeyEventArgs & key)
{
	auto it = m_keys.find(key.key);
	if (it != m_keys.end())
	{
		it->second = true;
	}
}

void Keyboard::onKeyRelease(ofKeyEventArgs & key)
{
	auto it = m_keys.find(key.key);
	if (it != m_keys.end())
	{
		it->second = false;
	}
}

const std::map<char, bool> & Keyboard::getKeys()
{
	return m_keys;
}

void Keyboard::setFilter(const std::set<char> & filter)
{
	// we want a new keymap with the keys in the filter
	// but keeping the old keys in case they are still pressed

	// create a new map
	std::map<char, bool> keys;
	
	// add the current values to the new map if they already exist, or initialize to false
	for (auto key : filter)
	{
		keys[key] = false;

		auto it = m_keys.find(key);
		if (it != m_keys.end())
		{
			keys[key] = it->second;
		}
	}

	// update our filter
	m_keys = keys;
}

void Keyboard::clear()
{
	for (auto & key : m_keys)
	{
		key.second = false;
	}
}
