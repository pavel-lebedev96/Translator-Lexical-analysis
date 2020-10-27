#include "perm_table.h"
void perm_table::add_item(const std::string & item)
{
	std::vector<std::string>::iterator it = table.begin();
	while (it != table.end() && item > *it) it++;
	table.insert(it, item);
}
bool perm_table::find(std::string item, int &pos) const
{
	pos = 0;
	while (table[pos] < item) pos++;
	return table[pos] == item;
}
perm_table::perm_table(std::string file_name)
{
	std::ifstream file(file_name);
	if (!file.is_open()) throw;
	std::string temp;
	while (file >> temp) add_item(temp);
	file.close();
}