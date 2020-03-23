#include <iostream>
#include <time.h>

using namespace std;

void printInput(int** input, int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << input[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	if (n <= 0 || n > 500)
	{
		cout << "Uznal" << endl;
		return 0;
	}
	int** input = new int* [n];
	for (int i = 0; i < n; i++)
		input[i] = new int[n];
	srand(time(0));
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			input[i][j] = rand() % 10;
	printInput(input, n, n - 1);
	int iOfMax = 0;
	int currMax = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n; j++)
			if (currMax < input[i][j])
			{
				currMax = input[i][j];
				iOfMax = i;
			}
	for (int i = n - 2; i > iOfMax; i--)
		for (int j = 0; j < n; j++)
			input[i + 1][j] = input[i][j];
	for (int i = 0; i < n; i++)
		input[iOfMax + 1][i] = 0;
	printInput(input, n, n);

	int** main = new int* [n];
	for (int i = 0; i < n; i++)
		main[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			main[i][j] = input[j][i];
	printInput(main, n, n);

	int** extra = new int* [n];
	for (int i = 0; i < n; i++)
		extra[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			extra[i][j] = input[n - j - 1][n - i - 1];
	printInput(extra, n, n);
}