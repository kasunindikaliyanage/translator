#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <fstream>

#define PLUS  1
#define MINUS 2
#define MUL   3
#define DIV   4
#define NUM   5
#define O_PARAM   6
#define E_PARAM   7
#define POW		  8
#define OTHER	  99
#define EMPTY	  100

#define ID		50

#define START 20
#define END	  21
#define AUTO  22
#define OUT   23
#define SEMI_COLON 25
#define EQUAL	26
#define OUT 27

struct Token
{
	int token_type = -1;
	std::string value = "";

	Token(int _token_type, std::string _value) : token_type(_token_type), value(_value)
	{}
};


class SimpleLexer
{
	int line_count = 0;
	char next_char =' ';

	std::ifstream input_stream;

	bool compare_string(std::string str1, std::string str2)
	{
		if (str1.compare(str2) == 0)
			return true;

		return false;
	}

	char peek_next()
	{
		char str = input_stream.peek();
		return str;
	}

	void read_next()
	{
		input_stream.get(next_char);
		if (input_stream.eof())
			isEOF = true;
	}

public:
	bool isEOF = false;

	SimpleLexer(std::string file_name);

	Token* getNextToken()
	{
		read_next();

		while (!isEOF)
		{
			if (next_char == ' ' || next_char == '\t')
			{
				read_next();
				continue;
			}
			else if (next_char == '\n')
			{
				line_count += 1;
				read_next();
			}
			else
			{
				break;
			}
		}

		if (std::isdigit(next_char))
		{
			int v = 0;
			char chr;

			do {
				v = 10 * v + std::atoi(&next_char);
				chr = peek_next();
				if (std::isdigit(chr))
				{
					read_next();
					continue;
				}
				break;
			} while (true);

			return new Token(NUM, std::to_string(v));
		}
		else if (std::isalpha(next_char))
		{
			std::string* temp = new std::string();
			char chr;
			do {
				temp->append(1, next_char);
				chr = peek_next();
				if (std::isalnum(chr))
				{
					read_next();
					continue;
				}
				break;
			} while (true);

			if (compare_string(*temp, "out"))
			{
				return new Token(OUT, *temp);
			}
			else if (compare_string(*temp, "auto"))
			{
				return new Token(AUTO, *temp);
			}
			else if (compare_string(*temp, "START"))
			{
				return new Token(START, *temp);
			}
			else if (compare_string(*temp, "END"))
			{
				return new Token(END, *temp);
			}
			else
			{
				return new Token(ID, *temp);
			}
		}
		else if (next_char == '+')
		{
			return new Token(PLUS, std::string(1, next_char));
		}
		else if (next_char == '-')
		{
			return new Token(MINUS, std::string(1, next_char));
		}
		else if (next_char == '*')
		{
			return new Token(MUL, std::string(1, next_char));
		}
		else if (next_char == '/')
		{
			return new Token(DIV, std::string(1, next_char));
		}
		else if (next_char == '(')
		{
			return new Token(O_PARAM, std::string(1, next_char));
		}
		else if (next_char == ')')
		{
			return new Token(E_PARAM, std::string(1, next_char));
		}
		else if (next_char == '^')
		{
			return new Token(POW, std::string(1, next_char));
		}
		else if (next_char == ';')
		{
			return new Token(SEMI_COLON, std::string(1, next_char));
		}
		else if (next_char == '=')
		{
			return new Token(EQUAL, std::string(1, next_char));
		}
		else if (next_char == '\0' || next_char == '\n')
		{
			return new Token(EMPTY, std::string("Empty string"));
		}
		else
		{
			return new Token(OTHER, std::string(1, next_char));
		}
	}
};