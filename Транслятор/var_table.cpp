#include "lexemes.h"
#include "var_table.h"
int var_table::hash(std::string l_name)
{
	int summ = 0;
	for (auto i : l_name)
		summ += i;
	return summ % table.size();
}
var_table::var_table(const int size)
{
	table = std::vector<std::vector<T_lexemes>>(size);
}
bool var_table::add_lexeme(std::string l_name, std::pair<int, int>& l_pos)
{
	if (find_lexeme(l_name, l_pos)) return false;
	table[l_pos.first].push_back(T_lexemes(l_name));
	return true;
}
bool var_table::find_lexeme(std::string l_name, std::pair<int, int>& l_pos)
{
	l_pos.first = hash(l_name);
	if (table[l_pos.first].empty()) return false;
	l_pos.second = 0;
	for (auto i : table[l_pos.first])
	{
		if (i.name == l_name) return true;
		l_pos.second++;
	}
	return false;
}
bool var_table::get_l_attr_value(std::string l_name, std::string attr_name, int & attr_value)
{
	std::pair<int, int> l_pos;
	if (!find_lexeme(l_name, l_pos)) return false;
	return table[l_pos.first][l_pos.second].get_attr_value(attr_name, attr_value);
}
bool var_table::get_l_attr_value(std::pair<int, int>& l_pos, std::string attr_name, int& attr_value)
{	
	try
	{
		return table.at(l_pos.first).at(l_pos.second).get_attr_value(attr_name, attr_value);
	}
	catch (...)
	{
		return false;
	}
}
bool var_table::set_l_attr_value(std::string l_name, std::string attr_name, int attr_value)
{
	std::pair<int, int> l_pos;
	if (!find_lexeme(l_name, l_pos)) return false;
	return table[l_pos.first][l_pos.second].set_attr_value(attr_name, attr_value);
}

bool var_table::set_l_attr_value(std::pair<int, int>& l_pos, std::string attr_name, int attr_value)
{
	try
	{
		return table.at(l_pos.first).at(l_pos.second).set_attr_value(attr_name, attr_value);
	}
	catch (...)
	{
		return false;
	}
}
