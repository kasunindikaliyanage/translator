#pragma once
#include <map>
#include <string>

#include "lexer/token.h"

class context {

	std::map<std::string, token> env;
	context* prev = nullptr;
public:
	context(context* _prev):prev(_prev)
	{}

	void put(token*);
	token* get(token*);
};