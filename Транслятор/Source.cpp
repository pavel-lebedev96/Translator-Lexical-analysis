#include "translator.h"
#include <iostream>
int main()
{
	translator t("kwords.txt", "delim.txt", 100, 100);
	t.lex_analysis("program.txt");
}