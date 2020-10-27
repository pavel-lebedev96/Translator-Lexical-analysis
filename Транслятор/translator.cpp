#include "translator.h"

bool translator::is_letter(char c)
{
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_';
}

bool translator::is_digit(char c)
{
	int temp = c - '0';
	return temp >= 0 && temp < 10;
}

TToken* translator::get_token(std::ifstream& file, char *error)
{
	static int line = 1;
	std::pair<int, int> pos;
	int state = 0;
	char c;
	std::string str;
	error[0] = '\0';
	c = file.get();
	while (1)
	{
		switch (state)
		{
		case 0:
			if (c == EOF) return NULL;
			str.clear();
			str.push_back(c);
			if (is_digit(c))
			{
				state = 1;
				c = file.get();
				break;
			}
			if (is_letter(c))
			{
				state = 2;
				c = file.get();
				break;
			}
			if (c == '/')
			{
				state = 3;
				c = file.get();
				break;
			}
			if (c == '<')
			{
				state = 4;
				c = file.get();
				break;
			}
			if (c == '>')
			{
				state = 5;
				c = file.get();
				break;
			}
			if (t_delim.find(str, pos.first))
				return new TToken(delim, pos.first);
			if (c == '\t' || c == ' ')
			{
				c = file.get();
				break;
			}
			if (c == '\n')
			{
				c = file.get();
				line++;
				break;
			}
			state = 9;
			break;
		case 1:
			if (is_digit(c))
			{
				str.push_back(c);
				c = file.get();
				break;
			}
			file.unget();
			t_const.add_lexeme(str, pos);
			return new TToken(constant, pos.first, pos.second);
		case 2:
			if (is_digit(c) || is_letter(c))
			{
				str.push_back(c);
				c = file.get();
				break;
			}
			file.unget();
			if (t_kwords.find(str, pos.first))
				return new TToken(kword, pos.first);
			t_id.add_lexeme(str, pos);
			return new TToken(id, pos.first, pos.second);
		case 3:
			if (c == '/')
			{
				state = 6;
				c = file.get();
				break;
			}
			if (c == '*')
			{
				state = 7;
				c = file.get();
				break;
			}
			state = 9;
			break;
		case 4:
			if (c == '=') str.push_back(c);
			else file.unget();
			t_delim.find(str, pos.first);
			return new TToken(delim, pos.first);
		case 5:
			if (c == '=') str.push_back(c);
			else file.unget();
			t_delim.find(str, pos.first);
			return new TToken(delim, pos.first);
		case 6:
			if (c == '\n')
			{
				line++;
				state = 0;
				c = file.get();
				break;
			}
			if (c == EOF) return NULL;
			c = file.get();
			break;
		case 7:
			if (c == '*')
			{
				state = 8;
				c = file.get();
				break;
			}
			if (c == EOF)
			{
				state = 10;
				break;
			}
			c = file.get();
			break;
		case 8:
			if (c == '/')
			{
				state = 0;
				c = file.get();
				break;
			}
			if (c == EOF)
			{
				state = 10;
				break;
			}
			state = 7;
			c = file.get();
			break;
		case 9:
			sprintf(error, "Incorrect symbol '%c' in line %d", str[0], line);
			return NULL;
		case 10:
			sprintf(error, "Incorrect comment /*");
			return NULL;
		}
	}
}

translator::translator(std::string kwords_file_name,
	std::string delim_file_name,
	int t_number_size,
	int t_id_size) : t_kwords(kwords_file_name), t_delim(delim_file_name),
	t_id(t_id_size), t_const(t_number_size) {}

void translator::lex_analysis(std::string code_file_name)
{
	std::ifstream file(code_file_name);
	if (!file.is_open()) throw;
	std::ofstream error_file("error.txt");
	std::ofstream token_file("tokens.txt");
	TToken* token = NULL;
	char error[100];
	while (token = get_token(file, error))
	{
		token_file << token->lex_type << " ";
		token_file << token->pos.first << " ";
		token_file << token->pos.second << std::endl;
	}
	if (error[0] != '\0')
		error_file << error;
	token_file.close();
	error_file.close();
}

