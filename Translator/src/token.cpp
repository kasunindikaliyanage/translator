#include "lexer/token.h"

token::token(std::string _value, TAG _type)
{
	value = _value;
	type = _type;
}

token::token(int _value, TAG _type)
{
	ivalue = _value;
	type = _type;
}

token::token(float _value, TAG _type)
{
	fvalue = _value;
	type = _type;
}