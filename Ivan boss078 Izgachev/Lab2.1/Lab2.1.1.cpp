#include <iostream>

using namespace std;

int tetEdge = 0;

int Menu() {
	int input, inputValue;
	cout << "Menu:" << endl;
	cout << "1. Set length of tetrahedron's edge." << endl;
	cout << "2. Get sum of all tetrahedron's edges." << endl;
	cout << "3. Get area of all tetrahedron's surfaces." << endl;
	cout << "4. Get voulume of the tetrahedron." << endl;
	cout << "5. Get tetrahedron's height." << endl;
	cout << "6. Get inscribed ball's radius." << endl;
	cout << "7. Credits and version." << endl;
	cout << "8. Exit." << endl;
	scanf_s("%d", &input);
	scanf_s("%*[^\n]");

	switch (input) {
	case 1:
		cout << "Enter length: ";
		scanf_s("%d", &inputValue);
		scanf_s("%*[^\n]");
		if (inputValue > 0)
			tetEdge = inputValue;
		else
			cout << "Wrong input! Try again..." << endl;
		break;
	case 2:
		cout << "Value: " << tetEdge * 6 << endl;
		break;
	case 3:
		cout << "Value: " << tetEdge * tetEdge * sqrt(3) << endl;
		break;
	case 4:
		cout << "Value: " << tetEdge * tetEdge * tetEdge * sqrt(2) / 12 << endl;
		break;
	case 5:
		cout << "Value: " << tetEdge * sqrt(2. / 3.) << endl;
		break;
	case 6:
		cout << "Value: " << tetEdge * sqrt(6) / 4 << endl;
		break;
	case 7:
		cout << "This marvelous menu was created by Ivan \"boss078\" Izgachev." << endl;
		cout << "Version: 1.0-stable-lab-edition" << endl;
		break;
	case 8:
		cout << "Exiting..." << endl;
		return 1;
	default:
		cout << "Wrong input! Try again..." << endl;
		break;
	}
	return 0;
}



int main() {
	while(Menu() == 0)
	{ }
	return 0;
}