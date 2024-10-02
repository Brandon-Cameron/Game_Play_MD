#pragma once
#include <iostream>

void FindAllVariables(char variables[1000], char code[1000])
{
	int varChar = 0;
	for (int i = 8; i < 1000; i++)
	{
		if (code[i] == 'i' && code[i + 1] == 'n' && code[i + 2] == 't')
		{
			//std::cout << code[i] << code[i + 1] << code[i + 2] << std::endl;
			int offset = 4;
			while (isalnum(code[i + offset]))
			{
				variables[varChar] = code[i + offset];
				varChar++;
				offset++;
			}
			variables[varChar] = ',';
			varChar++;

			std::cout << variables<< std::endl;
		}
		if (code[i] == 'c' && code[i + 1] == 'h' && code[i + 2] == 'a' && code[i + 3] == 'r')
		{
			int offset = 5;
			while (isalnum(code[i + offset]))
			{
				variables[varChar] = code[i + offset];
				varChar++;
				offset++;
			}
			variables[varChar] = ',';
			varChar++;

			std::cout << variables << std::endl;
		}
	}
}
void FindAllVariablesInScope(char variables[1000], char code[1000], int lineNumber)
{
	int varChar = 0;
	for (int i = 8; i < 1000; i++)
	{
		if (code[i] == 'i' && code[i + 1] == 'n' && code[i + 2] == 't')
		{
			//std::cout << code[i] << code[i + 1] << code[i + 2] << std::endl;
			int offset = 4;
			while (isalnum(code[i + offset]))
			{
				variables[varChar] = code[i + offset];
				varChar++;
				offset++;
			}
			variables[varChar] = ',';
			varChar++;

			std::cout << variables << std::endl;
		}
		if (code[i] == 'c' && code[i + 1] == 'h' && code[i + 2] == 'a' && code[i + 3] == 'r')
		{
			int offset = 5;
			while (isalnum(code[i + offset]))
			{
				variables[varChar] = code[i + offset];
				varChar++;
				offset++;
			}
			variables[varChar] = ',';
			varChar++;

			std::cout << variables << std::endl;
		}
	}
}