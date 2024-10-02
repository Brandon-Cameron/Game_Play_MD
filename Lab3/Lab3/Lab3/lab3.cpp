#include "lab3.h"
// add your tests here.
int main()
{

	char code[1000] = "int main() \n{\n int var1 = 10; \n char var2 = 10; \n if (var1 < 10) \n {\n int var3 = 20; \n} \n}\ n";

	if (code[11] == '\n')
	{
		std::cout << "awrshgsgeg" << "\n";
	}
	char variables[1000] = "";
	FindAllVariables(variables, code);


	char code2[1000] = "int main()\n{\n int numElephants = 10; \n int var2 = 10; \n	if (var2 < 10)\n{\nint var3 = 20; \n}\n while (var2 < 0)\n {\n if (var2 == 10) \n {\n int var4; \n} \n	int num = 10; \n} \n int var5 = 10; \n}";
	char variables2[1000] = "";
	FindAllVariablesInScope(variables2, code2, 12);


}