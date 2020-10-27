#pragma once
#include <string>
#include <vector>
#include <fstream>
class perm_table
{
	/*���������� ��������*/
	void add_item(const std::string & item);
	/*���������� �������*/
	std::vector<std::string> table;
public:
	/*�����������: ������ �� �����*/
	perm_table(std::string file_name);
	/*����� ��������: ���� ������� item ������,
	���������� true � ������� ��������, ����� - false*/
	bool find(std::string item, int &pos) const;
};