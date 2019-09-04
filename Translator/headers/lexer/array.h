#pragma once

#include "type.h"

class _array:  _type {
public:
	_type* of;
	int size;

	_array(const _type*, int);
	std::string toString();
};