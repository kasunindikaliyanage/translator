#pragma once
#include "token.h"

class num :  token {
public:
	int value = 0;
	num(TAG, int);
};