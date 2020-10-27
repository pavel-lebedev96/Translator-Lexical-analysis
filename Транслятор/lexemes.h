#pragma once
#include <vector>
#include <string>
/*��������� �������� ���������*/
struct T_attributes
{
	std::string name;
	int value;
};

class T_lexemes
{
	//������ ���������
	std::vector<T_attributes> attributes;

	/*������� ������: ����� �������� attr_name, 
	���� ������, �� ���������� true � ������� attr_pos, ����� - false*/
	bool find_attribute(std::string attr_name, int &attr_pos);
public:

	/*��� (�������������) �������*/
	std::string name;

	/*�����������: ������� ������� � ������ ������� ��������� � ������ l_name*/
	T_lexemes(std::string l_name);

	/*get-�������: ����� �������� � ������ attr_name;
	� ������ ������ ���������� true � �������� �������� attr_value, ����� - false*/
	bool get_attr_value(std::string attr_name, int &attr_value);

	/*set-�������: ����� �������� � ������ attr_name, 
	���� ����������� ��� ��� �������� ���������� �� attr_value, 
	���������� ���������� ������ �������� � ������������ true, ����� - false*/
	bool set_attr_value(std::string attr_name, int attr_value);
};
