#pragma once
#include <iostream>

bool isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int Reversed(int testNumber)
{
	return false;
}
bool isAPalindrome(int testNumber)
{
	int num = testNumber;
	int palin = 0;

	while (num > 0)
	{
		palin = palin * 10 + (num % 10);
		num /= 10;
	}
	if (palin == testNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isAPrimeNumber(int numbertoTest)
{
	if (numbertoTest == 2 || 3 || 5 || 7)
	{
		return true;
	}
	if (
		numbertoTest % 2 != 0 &&
		numbertoTest % 3 != 0 &&
		numbertoTest % 4 != 0 &&
		numbertoTest % 5 != 0 &&
		numbertoTest % 6 != 0 &&
		numbertoTest % 7 != 0 &&
		numbertoTest % 8 != 0 &&
		numbertoTest % 9 != 0
		)
	{
		return true;
	}
	return false;
}
int input5CharsConvertToInt()
{
	int returnInt = 0;
	char inputChar;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> inputChar;
		//check if its a digit.
		//do something

	}
	return returnInt;
}
int convertBinarytoDecimal(int binaryNumber)
{
	return 0;
}
void drawRightAngledTriangle()
{

}
void drawIsocelesTriangle()
{

}
void drawIsocelesTriangle2()
{

}

int find(int size, int arr[], int toFind)
{
	return -1;
}
int find2ndLargest(int size, int arr[])
{
	return -1;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
	return;
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{

	return false;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{

	return true;
}
int frequencyCount(int size, int arr[], int value)
{

	return 0;
}
int countDuplicates(int size, int arr[])
{

	return 0;
}
void reverse(int size, int arr[])
{
	return;
}
int rotateLeft(int size, int arr[])
{
	return -1;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	return false;
}
int wordCounter(int size, char characters[])
{
	return 0;
}