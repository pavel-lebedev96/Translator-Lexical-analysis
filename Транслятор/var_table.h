#pragma once
#include "lexemes.h"
class var_table
{
	/*���-�������: ����� ���� �������� % ������*/
	int hash(std::string l_name);

	/*���������� �������*/
	std::vector < std::vector<T_lexemes>> table;
public:

	/*�����������: ������� ������� �������� size*/
	var_table(int size);

	/*������� ���������� ������� � ������ l_name, 
	���� ������� ����������, �� false, ����� true, �������� ���� � ������� � �������*/
	bool add_lexeme(std::string l_name, std::pair<int, int>& l_pos);

	/*������� ������ ������� � ������ l_name, 
	���� ������� �������, �� ������������ true, �������� ���� � ������� � �������, 
	����� - false*/
	bool find_lexeme(std::string l_name, std::pair<int, int>&l_pos);

	/*get-�������: ����� ������� � ������ l_name, 
	���� �������, ����� get_attr_value, ����� false */
	bool get_l_attr_value(std::string l_name, std::string attr_name, int & attr_value);
	
	/*get-�������: ����� ������� � �������� l_pos (�������� ���� � ������� � �������),
	���� �������, ����� get_attr_value, ����� false */
	bool get_l_attr_value(std::pair<int, int>& l_pos, std::string attr_name, int& attr_value);

	/* set-�������: ����� ������� l_name, 
	���� �������, ����� set_attr_value, ����� false */
	bool set_l_attr_value(std::string l_name, std::string attr_name, int attr_value);

	/* set-�������: ����� ������� � �������� l_pos (�������� ���� � ������� � �������),,
	���� �������, ����� set_attr_value, ����� false */
	bool set_l_attr_value(std::pair<int, int>& l_pos, std::string attr_name, int attr_value);
};
