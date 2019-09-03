#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>

#include "token.h"

const static std::shared_ptr<token> AND_sptr = std::make_shared<token>("&&", TAG::AND);
const static std::shared_ptr<token> OR_sptr = std::make_shared<token>("||", TAG::OR);
const static std::shared_ptr<token> EQ_sptr = std::make_shared<token>("==", TAG::EQ);
const static std::shared_ptr<token> NEQ_sptr = std::make_shared<token>("!=", TAG::NEQ);
const static std::shared_ptr<token> LE_sptr = std::make_shared<token>("<=", TAG::LE);
const static std::shared_ptr<token> GE_sptr = std::make_shared<token>(">=", TAG::GE);
const static std::shared_ptr<token> IF_sptr = std::make_shared<token>("if", TAG::IF);
const static std::shared_ptr<token> ELSE_sptr = std::make_shared<token>("else", TAG::ELSE);
const static std::shared_ptr<token> BREAK_sptr = std::make_shared<token>("break", TAG::BREAK);
const static std::shared_ptr<token> WHILE_sptr = std::make_shared<token>("while", TAG::WHILE);
const static std::shared_ptr<token> DO_sptr = std::make_shared<token>("do", TAG::DO);
const static std::shared_ptr<token> TRUE_sptr = std::make_shared<token>("true", TAG::TRUE);
const static std::shared_ptr<token> FLASE_sptr = std::make_shared<token>("false", TAG::FALSE);
const static std::shared_ptr<token> INT_sptr = std::make_shared<token>("int", TAG::BASIC);
const static std::shared_ptr<token> FLOAT_sptr = std::make_shared<token>("float", TAG::BASIC);
const static std::shared_ptr<token> CHAR_sptr = std::make_shared<token>("char", TAG::BASIC);
const static std::shared_ptr<token> BOOL_sptr = std::make_shared<token>("bool", TAG::BASIC);

class lexer {

private:
	std::ifstream input_stream;
	char current_char = ' ';
	int number_of_lines = 0;
	std::map<std::string,std::shared_ptr<token>> reserve_words;

	void init()
	{
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("if", IF_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("else", ELSE_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("while", WHILE_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("do", DO_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("break", BREAK_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("true", TRUE_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("false", FLASE_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("int", INT_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("float", FLOAT_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("char", CHAR_sptr));
		reserve_words.insert(std::pair<std::string, std::shared_ptr<token>>("bool", BOOL_sptr));
	}

public:
	bool isEOF = false;
	lexer(std::string file_name);

	std::shared_ptr<token> scan();

	void read_next();
	bool compare_next_char(char next);
};