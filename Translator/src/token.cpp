#include "../headers/token.h"

token::token(std::string _value, tag_types _type)
{
	value = _value;
	type = _type;
}

token::token(int _value, tag_types _type)
{
	ivalue = _value;
	type = _type;
}

token::token(float _value, tag_types _type)
{
	fvalue = _value;
	type = _type;
}