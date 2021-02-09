#pragma once
#include <vector>
#include <string>
/*структура хранение атрибутов*/
struct T_attributes
{
	std::string name;
	int value;
};

class T_lexemes
{
	//вектор атрибутов
	std::vector<T_attributes> attributes;

	/*функция поиска: поиск атрибута attr_name, 
	если найден, то возвращает true и позицию attr_pos, иначе - false*/
	bool find_attribute(std::string attr_name, int &attr_pos);
public:

	/*имя (идентификатор) лексемы*/
	std::string name;

	/*конструктор: создает лексему с пустым набором атрибутов и именем l_name*/
	T_lexemes(std::string l_name);

	/*get-функция: поиск атрибута с именем attr_name;
	В случае успеха возвращает true и значение атрибута attr_value, иначе - false*/
	bool get_attr_value(std::string attr_name, int &attr_value);

	/*set-функция: поиск атрибута с именем attr_name, 
	если отсутствует или его значение отличается от attr_value, 
	происходит добавление нового атрибута и возвращается true, иначе - false*/
	bool set_attr_value(std::string attr_name, int attr_value);
};
