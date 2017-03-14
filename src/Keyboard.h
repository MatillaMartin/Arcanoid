#pragma once

#include <vector>
#include <set>
#include "ofEvents.h"

class Keyboard
{
public:
	Keyboard(const std::set<char> & filter);
	const std::map<char, bool> & getKeys();

	void setFilter(const std::set<char> & filter);
	void clear();

private:
	void onKeyPress(ofKeyEventArgs & key);
	void onKeyRelease(ofKeyEventArgs & key);

	std::map<char, bool> m_keys;
};