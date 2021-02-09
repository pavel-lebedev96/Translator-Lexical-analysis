#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "perm_table.h"
#include "var_table.h"
enum Type { kword, id, delim, constant };
struct TToken
{
	/*тип лексемы*/
	Type lex_type;
	/*позиция лексемы:
	для постоянной таблицы: pos.first = позиция, pos.second = -1
	для переменной таблицы: pos.first = знач-е хеш-функции,
	pos.second=номер цепочки*/
	std::pair<int, int> pos;
	TToken(Type _lex_type, int first_pos, int second_pos = -1)
	{
		lex_type = _lex_type;
		pos.first = first_pos;
		pos.second = second_pos;
	}
};
class translator
{
	/*проверка, что символ является буквой*/
	bool is_letter(char c);
	/*проверка, что символ является цифрой*/
	bool is_digit(char c);
	/*таблицы ключевых слов и разделителей*/
	perm_table t_kwords, t_delim;
	/*таблицы констант и идентификаторов*/
	var_table t_const, t_id;
	/*получение токена*/
	TToken* get_token(std::ifstream& file, char *error);
public:
	/*конструктор: 
	параметры - имена файлов для постоянных таблиц и 
	размеры переменных таблиц*/
	translator(std::string kwords_file_name, 
		std::string delim_file_name,  
		int t_const_size, int t_id_size);
	/*лексический анализ*/
	void lex_analysis(std::string code_file_name);
};