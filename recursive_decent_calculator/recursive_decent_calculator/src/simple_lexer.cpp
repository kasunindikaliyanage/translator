#include "../headers/simple_lexer.h"

SimpleLexer::SimpleLexer(std::string file_name)
{
	isEOF = false;
	input_stream.open(file_name);
}