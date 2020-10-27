#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "perm_table.h"
#include "var_table.h"
enum Type { kword, id, delim, constant };
struct TToken
{
	/*��� �������*/
	Type lex_type;
	/*������� �������:
	��� ���������� �������: pos.first = �������, pos.second = -1
	��� ���������� �������: pos.first = ����-� ���-�������,
	pos.second=����� �������*/
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
	/*��������, ��� ������ �������� ������*/
	bool is_letter(char c);
	/*��������, ��� ������ �������� ������*/
	bool is_digit(char c);
	/*������� �������� ���� � ������������*/
	perm_table t_kwords, t_delim;
	/*������� �������� � ���������������*/
	var_table t_const, t_id;
	/*��������� ������*/
	TToken* get_token(std::ifstream& file, char *error);
public:
	/*�����������: 
	��������� - ����� ������ ��� ���������� ������ � 
	������� ���������� ������*/
	translator(std::string kwords_file_name, 
		std::string delim_file_name,  
		int t_const_size, int t_id_size);
	/*����������� ������*/
	void lex_analysis(std::string code_file_name);
};