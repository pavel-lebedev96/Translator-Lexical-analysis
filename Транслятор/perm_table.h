#pragma once
#include <string>
#include <vector>
#include <fstream>
class perm_table
{
	/*добавление элемента*/
	void add_item(const std::string & item);
	/*постоянная таблица*/
	std::vector<std::string> table;
public:
	/*конструктор: чтение из файла*/
	perm_table(std::string file_name);
	/*поиск элемента: если элемент item найден,
	возвращает true и позицию элемента, иначе - false*/
	bool find(std::string item, int &pos) const;
};