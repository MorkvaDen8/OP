#include "functions.h"

void Book::SetValues() {
	cin.ignore();
	cout << "Enter PIB: ";
	getline(cin, PIB);

	cout << "Enter book name: ";
	getline(cin, name);

	cout << "Enter book year: ";
	cin >> year;

	cout << "Enter book pages: ";
	cin >> pages;
}

void Book::SetValues(string newPIB, string newName, int newYear, int newPages) {
	PIB = newPIB;
	name = newName;
	year = newYear;
	pages = newPages;
}

string Book::GetPIB() {
	return PIB;
}

string Book::GetName() {
	return name;
}

int Book::GetYear() {
	return year;
}

int Book::GetPages() {
	return pages;
}

void Book::Print() {
	cout << "PIB : " << PIB << endl;
	cout << "Name : " << name << endl;
	cout << "Year : " << year << endl;
	cout << "Pages : " << pages << endl;
	cout << "---------------------------------------------------------" << endl;
}

void SearchMax(Book* array, int size) {
	int BeginYear, EndYear, j = 0;
	cout << "Enter YearBegin: ";
	cin >> BeginYear;
	cout << "Enter YearEnd: ";
	cin >> EndYear;
	cout << endl << endl;
	Book* newArray = new Book[size];
	for (int i = 0; i < size; i++) {
		if (array[i].GetYear() > BeginYear && array[i].GetYear() < EndYear) {
			newArray[j].SetValues(array[i].GetPIB(), array[i].GetName(), array[i].GetYear(), array[i].GetPages());
			j++;
		}
	}
	string max1 = newArray[0].GetPIB(), max2 = newArray[0].GetName();
	int max3 = newArray[0].GetYear(), max4 = newArray[0].GetPages();

	for (int i = 1; i < j; i++) {
		if (newArray[i].GetPages() > max4) {
			max1 = newArray[i].GetPIB();
			max2 = newArray[i].GetName();
			max3 = newArray[i].GetYear();
			max4 = newArray[i].GetPages();
		}
	}

	for (int i = 0; i < j; i++) {
		newArray[i].Print();
	}

	cout << endl << "Book with maximum Pages(" << BeginYear << "-" << EndYear << "): " << endl;
	cout << "PIB :" << max1 << endl;
	cout << "Name :" << max2 << endl;
	cout << "Year :" << max3 << endl;
	cout << "Pages :" << max4 << endl;

	delete[] newArray;
}