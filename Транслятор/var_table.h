#pragma once
#include "lexemes.h"
class var_table
{
	/*хеш-функция: сумма всех символов % размер*/
	int hash(std::string l_name);

	/*переменная таблица*/
	std::vector < std::vector<T_lexemes>> table;
public:

	/*конструктор: создает таблицу размером size*/
	var_table(int size);

	/*функция добавления лексемы с именем l_name, 
	если лексема существует, то false, иначе true, значение хеша и позиция в цепочке*/
	bool add_lexeme(std::string l_name, std::pair<int, int>& l_pos);

	/*функция поиска лексемы с именем l_name, 
	если лексема найдена, то возвращаются true, значение хеша и позиция в цепочке, 
	иначе - false*/
	bool find_lexeme(std::string l_name, std::pair<int, int>&l_pos);

	/*get-функция: поиск лексемы с именем l_name, 
	если найдена, вызов get_attr_value, иначе false */
	bool get_l_attr_value(std::string l_name, std::string attr_name, int & attr_value);
	
	/*get-функция: поиск лексемы с адрессом l_pos (значение хеша и позиция в цепочке),
	если найдена, вызов get_attr_value, иначе false */
	bool get_l_attr_value(std::pair<int, int>& l_pos, std::string attr_name, int& attr_value);

	/* set-функция: поиск лексемы l_name, 
	если найдена, вызов set_attr_value, иначе false */
	bool set_l_attr_value(std::string l_name, std::string attr_name, int attr_value);

	/* set-функция: поиск лексемы с адрессом l_pos (значение хеша и позиция в цепочке),,
	если найдена, вызов set_attr_value, иначе false */
	bool set_l_attr_value(std::pair<int, int>& l_pos, std::string attr_name, int attr_value);
};
