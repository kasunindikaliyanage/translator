#include "lexer/token.h"

token::token(TAG _type): type(_type)
{
}

token::token( const char* _str, TAG _type) : type(_type), str(_str)
{
}

token::token(int _value, TAG _type) : type(_type), int_value(_value)
{
}

token::token(double _value, TAG _type) : type(_type), double_value(_value)
{
}