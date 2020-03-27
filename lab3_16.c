#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int CountEveryStar(int** a, int m, int n)
{
	int count = 0;

	/*while(move+1<m*n)
	{
		move++;
		if(move%m == 0)							//смотрим, не упёрлись ли мы в стенку массива
		{
			count = 0;
		}


		if (a[move] == 1)
			count++;
		else
			count = 0;

		a[move] == 1 ? count++ : count = 0;			//тернарное представление проверки, крестик или нолик

		if (count == 5)								//проверка на выигрыш
			return count;
	}*/

	for (int i = 0; i < n; i++)							//Проход по строкам
	{
		count = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
				count++;
			else
				count = 0;

			if (count == 5)
				return count;
		}
	}

	for (int i = 0; i < m; i++)						//Проход по столбцам
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j][i] == 1)
				count++;
			else
				count = 0;

			if (count == 5)
				return count;
		}
	}

	for (int i = n - 1; i >= 0; i--)						//Проход по диагонали сверху слева вниз право
	{
		int j = 0;
		int line = i;
		while (line < n && j < m)
		{
			if (a[line][j] == 1)
				count++;
			else
				count = 0;

			if (count == 5)
				return count;

			j++;
			line++;
		}
	}

	for (int i = n - 1; i >= 0; i--)						//Проход по другой диагонали
	{
		int j = m - 1;
		int line = i;
		while (line < n && j >= 0)
		{
			if (a[line][j] == 1)
				count++;
			else
				count = 0;

			if (count == 5)
				return count;

			j--;
			line++;
		}
	}

	return 0;

}

int main()
{
	int m = 0;
	int n = 0;
	int move = 0;
	bool win = false;

	printf("Enter m and n: ");
	scanf_s("%d%d", &m, &n);

	int** a = (int**)malloc(n * m * sizeof(int*));
	// Ввод элементов массива
	for (int i = 0; i < n; i++)  // цикл по строкам
	{
		// Выделение памяти под хранение строк
		a[i] = (int*)malloc(m * sizeof(int));
		for (int j = 0; j < m; j++)  // цикл по столбцам
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}


	if (CountEveryStar(a, m, n) == 5)
	{
		win = true;
	}

	if (win)
		printf("!WIN!");
	else
		printf("\n!TONIGHT YOU DIE!");

	getchar();
	return 0;
}
