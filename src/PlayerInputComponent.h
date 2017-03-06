#pragma once

#include "ofxEntityX.h"
#include "UserCommand.h"

class PlayerInputComponent : public Component<PlayerInputComponent>
{
public:
	PlayerInputComponent(char left, char right, char up, char down, char use);

	bool parse(char input, UserCommand & command);

private:
	char m_left; 
	char m_right; 
	char m_up; 
	char m_down;
	char m_use;
};