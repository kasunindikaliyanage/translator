#include "lexer/word.h"

word::word(TAG _tag, std::string _lexeme):token(_tag)
{
	lexeme = _lexeme;
}

std::string word::toString()
{
	return lexeme;
}