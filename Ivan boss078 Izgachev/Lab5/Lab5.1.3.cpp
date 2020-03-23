#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;

typedef struct node {
	char data;
	struct node* prev;
	struct node* next;
} Node;

typedef struct customstring {
	Node* head;
	Node* tail;
	int length;
} CustomString;

void addChar(CustomString* custStr, char a) {
	if (!((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122)))
		return;
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = a;
	p->next = nullptr;
	p->prev = nullptr;
	if (custStr->head == nullptr) {
		custStr->head = custStr->tail = p;
	}
	else {
		custStr->tail->next = p;
		p->prev = custStr->tail;
		custStr->tail = p;
	}
	custStr->length++;
}

CustomString initCustString(char* initStr) {
	CustomString custStr = { nullptr, nullptr, 0 };
	for (int i = 0; i < strlen(initStr); i++) {
		addChar(&custStr, initStr[i]);
	}
	return custStr;
}

bool isPalindrom(CustomString* custStr) {
	if (custStr->head == nullptr)
		return true;
	char* first = new char[custStr->length + 1];
	char* second = new char[custStr->length + 1];

	Node* curr = custStr->tail;
	for (int i = 0; i < custStr->length; i++, curr = curr->prev) {
		first[i] = curr->data;
	}
	first[custStr->length] = '\0';

	curr = custStr->head;
	for (int i = 0; i < custStr->length; i++, curr = curr->next) {
		second[i] = curr->data;
	}
	second[custStr->length] = '\0';

	return !strcmp(first, second);
}

int main() {
	cout << "Enter string: " << endl;
	char* input = new char[255];
	cin.getline(input, 255);
	CustomString custStr = initCustString(input);
	if (isPalindrom(&custStr))
		cout << "This string is palindrom" << endl;
	else 
		cout << "This string is not palindrom" << endl;
	return 0;
}