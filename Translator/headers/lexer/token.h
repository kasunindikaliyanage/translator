#pragma once

#include <string>

enum class TAG {
	INITIAL = 0,
	NOT_DEFINED = 100,
	AND = 256,
	BASIC = 257,
	BREAK = 258,
	DO = 259,
	ELSE = 260,
	EQ = 261,
	FALSE = 262,
	GE = 263,
	ID = 264,
	IF = 265,
	INDEX = 266,
	LE = 267,
	MINUS = 268,
	NEQ = 269,
	NUM = 270,
	OR = 271,
	REAL = 272,
	TEMP = 273,
	TRUE = 274,
	WHILE = 275
};

class token {

public:
	const char* str;
	int int_value = 0;
	double double_value = 0.0;

	TAG type= TAG::INITIAL;
	token(TAG);
	token(const char*, TAG );
	token(int, TAG);
	token(double, TAG);
};