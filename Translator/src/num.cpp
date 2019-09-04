#include "lexer/num.h"

num::num(TAG _tag, int _value) :token(_tag)
{
	value = _value;
}