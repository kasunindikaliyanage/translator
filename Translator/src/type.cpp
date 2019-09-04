#include "lexer/type.h"

_type::_type(TAG _tag, std::string _value, int _width) :word(_tag, _value)
{
	width = _width;
}