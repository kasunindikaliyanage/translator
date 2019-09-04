#include "lexer/array.h"

_array::_array(const _type* _t, int _size):_type(TAG::INDEX,"[]", _size*(*_t).width)
{
	size = _size;
	of = (_type*)_t;
}