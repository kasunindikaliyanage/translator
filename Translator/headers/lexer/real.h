#pragma once

#include "token.h"

class real : token {
public:
	float value =0.0;
	real(TAG,float);
	std::string toString();
};
