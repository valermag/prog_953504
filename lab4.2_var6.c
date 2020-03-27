#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

/*
 * Итак, принцип работы:
 * Считывая из файла, буду доставать строки fgets-ом, который буду обрабатывать ф-цией ModifyingSTR
 * Она сдвигает на одну позицию строку, т.е. с каждой новой строкой просто будет вызываться count++ раз.
 */

void ModifyingSTR(char* str)
{
	int len = strlen(str);
	char buffer = str[len - 2];								//в буффер кидаю самую последнюю букву, т.к. она сотрётся сразу, потом её кину в начало
	for(int i=len-3; i>=0; i--)								//передвигаю каждую букву вправо
	{
		str[i + 1] = str[i];
	}
	str[0] = buffer;										//кидаю в начало
}

int main()
{
	char str[100];
	FILE* file;

	//считывание строк
	fopen_s(&file, "C://Users/Lenovo/source/repos/TestProject/TestApplication/input.txt", "r+");
	
	if (file == NULL)										//проверка на дурака
	{
		printf("\nERROR\n");
		getchar();
		fclose(file);
		return 0;
	}
	else
	{
		int count = 0;
		while (feof(file) != EOF)							//пока не дойдём до каонца файла(EOF) и пошли
		{
			if (fgets(str, 100, file))				//считываем строку
			{
				count++;
				for (int i = 0; i < count; i++)				//передвигаем n раз
				{
					ModifyingSTR(str);
				}
				printf("\n|%s|\n", str);				//выводим
			}
		}
	}
	getchar();
	fclose(file);
	return 0;
}
