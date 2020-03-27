#include <iostream>

using namespace std;

double fact(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (double)(n * fact(n - 1));
}

int main() {
	int n = 0;
	double curr = 0, epsilon, x;
	cout << "Enter x: " << endl;
	cin >> x;
	cout << "Enter epsilon: " << endl;
	cin >> epsilon;
	do {
		n++;
		curr += pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1));
	} while (abs(sin(x) - curr) >= epsilon);
	cout << "n= " << n << ", current= " << curr << ", sin(x)= " << sin(x);
	return 0;
}