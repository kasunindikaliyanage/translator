#include <iostream>
#include "lexer/lexer.h"

int main()
{
	lexer my_lexer("tests/test1.txt");
	while (!my_lexer.isEOF)
	{
		token* st = my_lexer.scan();

		if (st != nullptr)
		{
			//token t = st.get();
			if(st->type != TAG::NUM && st->type != TAG::REAL )
				std::cout << "value : " << st->str  << std::endl;
			else if(st->type != TAG::REAL)
				std::cout << "value : " << st->int_value  << std::endl;
			else
				std::cout << "value : " << st->double_value << std::endl;
		}
	}
}
