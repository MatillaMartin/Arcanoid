#pragma once

#include <vector>
#include "ofEvents.h"
class Keyboard
{
public:
	Keyboard();
	const std::map<char, bool> & getKeys();

private:
	void onKeyPress(ofKeyEventArgs & key);
	void onKeyRelease(ofKeyEventArgs & key);

	std::map<char, bool> m_keys;
};