#include "dni.h"

vector <struct TOKEN> Tlist;

void register_token(string token)
{
	struct TOKEN T;
	if (token.length() < 1)
		return;
	if (token == "input") {
		T.type = INPUT;
	}
	else if (token == "end") {
		T.type = END;
	}
	else if (token == "output") {
		T.type = OUTPUT;
	}
	else if (token == "=") {
		T.type = EQUAL_TO;
	}
	else if (token == "<") {
		T.type = ASSIGNMENT;
	}
	else if (is_number(token)) {
		T.type = NUMBER;
		T.ivalue = token;
	}
	else if (is_string(token)) {
		T.type = STRING;
		string str = "";
		for (int i = 1; i < token.length() - 1; i++)
			str += token[i];
		T.svalue = str;
	}
	else if (is_name(token)) {
		T.type = VARIABLE;
		T.symbol = token
	}
	else {
		cout << "Error, " << token << " does not mean anything." << endl;
		return;
	}
	Tlist.push_back(T);
}

void print_tokens()
{
	for (int i = 0; i < Tlist.size(); i++) {
		cout << Tlist[i].type << "\t" << Tlist[i].value << endl;
	}
}

bool is_number(string token)
{
	for (int i = 0; i < token.length(); i++) {
		if ((token[i] < '0' || token[i] > '9') && token[i] != '.')
			return false;
	}
	return true;
}

bool is_name(string token)
{
	if (!((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z')))
		return false;
	for (int i = 0; i < token.length(); i++) {
		if (!((token[i] >= 'a' && token[i] <= 'z') || (token[i] >= 'A' && token[i] <= 'Z') || token[i] == '_'))
			return false;
	}
	return true;
}

bool is_string(string token)
{
	return ((token[0] == '\"') && (token[token.length() - 1] == '\"')) || ((token[0] == '\"') && (token[token.length() - 1] == '\"'));
}
