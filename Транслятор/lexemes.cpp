#include "lexemes.h"
bool T_lexemes::find_attribute(std::string attr_name, int &attr_pos)
{
	attr_pos = 0;
	for (auto i : attributes)
	{
		if (i.name == attr_name) return true;
		attr_pos++;
	}
	return false;
}

T_lexemes::T_lexemes(std::string l_name)
{
	name = l_name;
}

bool T_lexemes::get_attr_value(std::string attr_name, int &attr_value)
{
	int attr_pos;
	if (!find_attribute(attr_name, attr_pos)) return false;
	attr_value = attributes[attr_pos].value;
	return true;
}

bool T_lexemes::set_attr_value(std::string attr_name, int attr_value)
{
	int attr_pos;
	if (!find_attribute(attr_name, attr_pos))
	{
		attributes.push_back({ attr_name,attr_value });
		return true;
	}
	if (attributes[attr_pos].value == attr_value) return false;
	attributes[attr_pos].value = attr_value;
	return true;
}