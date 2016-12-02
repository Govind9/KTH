#include "dni.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return -1;
	ifstream file(argv[1]);
	if (file.fail())
		return -1;
	char c;
	string str = "";
	while (file.get(c)) {
		if (c == '<' || c == '=' || c == '\n' || c == ' ' || c == '\t') {
			if (c == '=' || c == '<') {
				str = "";
				str += c;
			}
			register_token(str);
			str = "";
			continue;
		} 
		str += c;
	}
	file.close();

	print_tokens();
	return 0;
}
