#pragma once

class DropComponent
{
public:
	enum DropType { NONE, STICK, SHOT /*...*/ };

	DropComponent(DropType type);
	
	DropType m_type;
};