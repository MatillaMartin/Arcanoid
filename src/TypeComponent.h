#pragma once

#include "ofxEntityX.h"

template<typename T>
class TypeComponent
{
public:
	TypeComponent(T type)
		:
		type(type)
	{}

	T type;
};