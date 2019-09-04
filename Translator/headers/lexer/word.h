#pragma once
#include "token.h"

class word : token{
public:
	std::string lexeme;

	word(TAG, std::string);

	std::string toString();

};