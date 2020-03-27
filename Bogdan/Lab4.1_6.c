#include <stdio.h>
#include <stdlib.h>
#include <iostream>

/*
 * Итак, принцип работы:
 * Буду проходиться по строке и искать пробелы
 * Потом отправлять в проверочную функцию(она будет булевая для удобства, чтобы возвращала хорошие данные удобные)
 * слова, которые буду вырезать по пробелам
 * Если индекс буквы меньше или равен индексу стоящей перед ней, возвращаю ложь и наоборот
 */

bool CheckYourself(char* str, int start, int n)				//Сама функция проверки слова, принимает указатель на первый элемент строки, индекс первой буквы слова и длинну слова
{
	for(int i=start; i<start+n-1; i++)
	{
		//if (!str[i + 1] > str[i])
			//return false;
		if (str[i + 1] < str[i] || str[i + 1] == str[i])
			return false;
	}
	
	return true;
}

void Print(char* str, int start, int n)					//Ф-ция печати слова, принимает то же самое, что и ф-ция проверки слова
{
	for(int i=start; i<start+n; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");
}

int main()
{
	int len = 0;
	int start = -1;												// старт равен -1, т.к. потом, находя пробел, нам надо будет добавить один, чтобы попасть на первую букву слова, а для первого слова мы, добавив один, попадём на нулевой индекс, всё крута
	char str[100];

	printf("Input string: ");
	gets_s(str);												//Ввод строки
	len = strlen(str);

	for(int i=0; i<=len; i++)
	{
		if (str[i] == ' ' || i == len)							//Если встречен пробел ИЛИ мы упёрлись в стенку строки
		{
			start++;
			if (CheckYourself(str, start, i - start))			//Проверка
				Print(str, start, i - start);					//Печать
			start = i;											//Переназначение места последнего пробела
		}
	}
	
	getchar();
	return 0;
}
