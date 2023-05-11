#include "functions.h"

int main() {
	int size, max;
	cout << "Enter quantity: ";
	cin >> size;
	Book* array = new Book[size];

	for (int i = 0; i < size; i++) {
		array[i].SetValues();
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		array[i].Print();
	}

	SearchMax(array, size);

	delete[] array;
	return 0;
}