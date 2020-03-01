#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <map>

#include "token.h"

static token AND_sptr	("&&", TAG::AND);
static token OR_sptr	("||", TAG::OR);
static token EQ_sptr	("==", TAG::EQ);
static token NEQ_sptr	("!=", TAG::NEQ);
static token LE_sptr	("<=", TAG::LE);
static token GE_sptr	(">=", TAG::GE);
static token IF_sptr	("if", TAG::IF);
static token ELSE_sptr("else", TAG::ELSE);
static token BREAK_sptr("break", TAG::BREAK);
static token WHILE_sptr("while", TAG::WHILE);
static token DO_sptr	("do", TAG::DO);
static token TRUE_sptr("true", TAG::TRUE);
static token FLASE_sptr("false", TAG::FALSE);
static token INT_sptr	("int", TAG::BASIC);
static token FLOAT_sptr("float", TAG::BASIC);
static token CHAR_sptr("char", TAG::BASIC);
static token BOOL_sptr("bool", TAG::BASIC);

class lexer {

private:
	std::ifstream input_stream;
	char current_char;
	int number_of_lines = 0;
	std::map<std::string,token> reserve_words;

	void init()
	{
		reserve_words.insert(std::pair<std::string, token>(std::string("if"), IF_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("else"), ELSE_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("while"), WHILE_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("do"), DO_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("break"), BREAK_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("true"), TRUE_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("false"), FLASE_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("int"), INT_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("float"), FLOAT_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("char"), CHAR_sptr));
		reserve_words.insert(std::pair<std::string, token>(std::string("bool"), BOOL_sptr));
	}

public:
	bool isEOF = false;
	lexer(std::string file_name);

	token* scan();

	void read_next();
	bool compare_next_char(char next);
};