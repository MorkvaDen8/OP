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
	cout << "6.Iterator in begin" << endl;
	cout << "7.Iterator in end" << endl;
	cout << "8.Value of element in position" << endl;
	cout << "9.Position Iterator ++" << endl;
	cout << "0.Exit" << endl;
	cout << "Enter you choice: " << endl;
	cin >> choice;
	return choice;
}

void menu1(int size) {
	Array<int> arr(size);
	Array<int>::Iterator Iter(&arr);
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
		case 6:
			Iter.BeginArray();
			cout << "Iterator position = 0" << endl;
			break;
		case 7:
			if (Iter.EndArray()) {
				cout << "Iterator position in end;" << endl;
			}
			else {
				cout << "Iterator position not in end;" << endl;
			}
			break;
		case 8:
			cout << "Value in position iterator: " << Iter.ValueElement() << endl;
			break;
		case 9:
			Iter.NextElement();
			cout << "Now iterator in position " << Iter.GetPosition() << endl;
			break;
		case 0:
			return;
		}
	}
}

void menu2(int size) {
	Array<float> arr(size);
	Array<float>::Iterator Iter(&arr);
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
		case 6:
			Iter.BeginArray();
			cout << "Iterator position = 0" << endl;
			break;
		case 7:
			if (Iter.EndArray()) {
				cout << "Iterator position in end;" << endl;
			}
			else {
				cout << "Iterator position not in end;" << endl;
			}
			break;
		case 8:
			cout << "Value in position iterator: " << Iter.ValueElement() << endl;
			break;
		case 9:
			Iter.NextElement();
			cout << "Now iterator in position " << Iter.GetPosition() << endl;
			break;
		case 0:
			return;
		}
	}
}

void menu3(int size) {
	Array<char> arr(size);
	Array<char>::Iterator Iter(&arr);
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
		case 6:
			Iter.BeginArray();
			cout << "Iterator position = 0" << endl;
			break;
		case 7:
			if (Iter.EndArray()) {
				cout << "Iterator position in end;" << endl;
			}
			else {
				cout << "Iterator position not in end;" << endl;
			}
			break;
		case 8:
			cout << "Value in position iterator: " << Iter.ValueElement() << endl;
			break;
		case 9:
			Iter.NextElement();
			cout << "Now iterator in position " << Iter.GetPosition() << endl;
			break;
		case 0:
			return;
		}
	}
}