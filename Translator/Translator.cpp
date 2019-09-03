#include <iostream>
#include "lexer/lexer.h"

int main()
{
	lexer my_lexer("tests/test1.txt");
	while (!my_lexer.isEOF)
	{
		std::shared_ptr<token> st = my_lexer.scan();

		if (st != nullptr)
		{
			token t = *st.get();
			std::cout << "value : " << t.value << " -- type : " << t.type << std::endl;
		}
	}

    std::cout << "Hello World!\n";
}

