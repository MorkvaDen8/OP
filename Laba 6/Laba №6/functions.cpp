#include "functions.h"

int ArrayType() {
	int type;
	cout << "1.Integer" << endl;
	cout << "2.Float" << endl;
	cout << "3.Char" << endl;
	cout << "Enter type of array: ";
	cin >> type;
	return type;
}

int TextMenu() {
	int choice;
	cout << endl;
	cout << "1.Position Element" << endl;
	cout << "2.New Element" << endl;
	cout << "3.Delete Element" << endl;
	cout << "4.Get size of array" << endl;
	cout << "5.Show array(Iterator)" << endl;
	cout << "0.Exit" << endl;
	cout << "Enter you choice: " << endl;
	cin >> choice;
	return choice;
}

void menu1(int size) {
	Array<int> arr(size);
	int choice = 1;
	while (choice != 0) {
		choice = TextMenu();
		switch (choice) {
		case 1:
			arr.PositionElement();
			break;
		case 2:
			arr.NewElement();
			break;
		case 3:
			arr.DeleteElement();
			break;
		case 4:
			cout << "Size of array: " << arr.GetSize() << endl;
			break;
		case 5:
			arr.ShowArray();
			break;
		case 0:
			return;
		}
	}
}

void menu2(int size) {
	Array<float> arr(size);
	int choice = 1;
	while (choice != 0) {
		choice = TextMenu();
		switch (choice) {
		case 1:
			arr.PositionElement();
			break;
		case 2:
			arr.NewElement();
			break;
		case 3:
			arr.DeleteElement();
			break;
		case 4:
			cout << "Size of array: " << arr.GetSize() << endl;
			break;
		case 5:
			arr.ShowArray();
			break;
		case 0:
			return;
		}
	}
}

void menu3(int size) {
	Array<char> arr(size);
	int choice = 1;
	while (choice != 0) {
		choice = TextMenu();
		switch (choice) {
		case 1:
			arr.PositionElement();
			break;
		case 2:
			arr.NewElement();
			break;
		case 3:
			arr.DeleteElement();
			break;
		case 4:
			cout << "Size of array: " << arr.GetSize() << endl;
			break;
		case 5:
			arr.ShowArray();
			break;
		case 0:
			return;
		}
	}
}