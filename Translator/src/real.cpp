#include "lexer/real.h"

real::real(TAG _tag, float _value):token(_tag)
{
	value = _value;
}

std::string real::toString()
{
	return std::to_string(value);
}