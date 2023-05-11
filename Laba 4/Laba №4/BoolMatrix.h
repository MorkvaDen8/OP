#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class BoolMatrix {
private:
	int n, m; //n - рядки m - стовпці
	int** arr;
public:
	BoolMatrix();
	BoolMatrix(int n, int m);
	BoolMatrix(const BoolMatrix& other);
	int GetN();
	int GetM();
	BoolMatrix operator |(const BoolMatrix& other);
	BoolMatrix operator ~();
	void PrintMatrix();
	int NumberOfUnits();
	~BoolMatrix();
};
