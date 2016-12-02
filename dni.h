#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum TYPE
{
	INPUT,
	OUTPUT,
	END,
	EQUAL_TO,
	ASSIGNMENT,
	VARIABLE,
	NUMBER,
	STRING,
};

struct TOKEN
{
	string symbol;
	string svalue;
	int ivalue;
	TYPE type;
};


void register_token(string);

void print_tokens();

bool is_number(string);

bool is_name(string);

bool is_string(string);
