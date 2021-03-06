#include "lexer/lexer.h"

lexer::lexer(std::string file_name)
{
	isEOF = false;
	input_stream.open(file_name);
	init();
}

void lexer::read_next()
{
	input_stream.get(current_char);
	if (input_stream.eof())
		isEOF = true;
}

bool lexer::compare_next_char(char comp_char)
{
	read_next();
	if (current_char != comp_char)
		return false;
	current_char = ' ';
	return true;
}

token* lexer::scan()
{
	for (; ; read_next())
	{
		if (isEOF)
		{
			return nullptr;
		}
		else if (current_char == ' ' || current_char == '\t')
		{
			continue;
		}
		else if (current_char == '\n')
		{
			number_of_lines++;
		}
		else
		{
			break;
		}
	}

	switch (current_char)
	{
	case '&':
		if (compare_next_char('&')) return &AND_sptr; else return new token("&", TAG::NOT_DEFINED) ;
	case '|':													  
		if (compare_next_char('|')) return &OR_sptr; else return  new token("|", TAG::NOT_DEFINED);
	case '=':													  
		if (compare_next_char('=')) return &EQ_sptr; else return  new token("=", TAG::NOT_DEFINED);
	case '!':													  
		if (compare_next_char('=')) return &NEQ_sptr; else return new token("!", TAG::NOT_DEFINED);
	case '<':													  
		if (compare_next_char('=')) return &LE_sptr; else return  new token("<", TAG::NOT_DEFINED);
	case '>':													  
		if (compare_next_char('=')) return &GE_sptr; else return  new token(">", TAG::NOT_DEFINED);
	}															  

	if (std::isdigit(current_char))
	{
		int v = 0;
		do
		{
			v = 10 * v + std::atoi(&current_char);
			read_next();
		} while (std::isdigit(current_char));

		if (current_char != '.')
			return new token(v, TAG::NUM);

		float r = v;
		float d = 10;

		for(;;)
		{
			read_next();
			if (!std::isdigit(current_char))
				break;

			r = r + std::atoi(&current_char) / d;
			d = d * 10;
		}
		return new token(r,TAG::REAL);
	}

	std::string* temp = new std::string();
	
	if (std::isalpha(current_char))
	{	
		do {
			temp->append(1,current_char);
			read_next();
		}
		while (std::isalnum(current_char));

		auto itr = reserve_words.find(*temp);
		if (itr != reserve_words.end())
		{
			return &(itr->second);
		}
		else
		{
			reserve_words.insert(std::pair<std::string, token>
				(*temp, *(new token(temp->c_str(), TAG::ID))));

			token* x = &reserve_words.find(*temp)->second;
			return &reserve_words.find(*temp)->second;
		}
	}

	temp->append(1, current_char);
	token* sptr = new token(temp->c_str(), TAG::NOT_DEFINED);
	current_char = ' ';
	return sptr;
}