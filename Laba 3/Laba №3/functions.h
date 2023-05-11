#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string PIB, name;
	int year, pages;
public:
	void SetValues();
	void SetValues(string newPIB, string newName, int newYear, int newPages);
	string GetPIB();
	string GetName();
	int GetYear();
	int GetPages(); 
	void Print();
};

void SearchMax(Book* array, int size);