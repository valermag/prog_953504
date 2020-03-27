#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n;
	ifstream input;
	input.open("input.txt");
	input >> n;
	char*** inputArr = new char** [n];
	int* heightArr = new int[n];
	for (int i = 0; i < n; i++) {
		input >> heightArr[i];
		inputArr[i] = new char* [heightArr[i]];
	}
	for (int i = 0; i < n; i++) {
		char* currStr = new char[255];
		input >> currStr;
		int curr = 0, currLength = 0, k = 0;
		do {
			curr += currStr[k];
			k++;
			currLength++;
		} while (currStr[k] != '\0' && currStr[k] != '\n');
		if (curr % 2 == 0)
			for (int f = currLength - 1; f >= 0; f--) {
				cout << currStr[f];
			}
		else 
			for (int f = 0; f < currLength; f++) {
				cout << currStr[f];
			}
		cout << endl;
	}

	return 0;
}