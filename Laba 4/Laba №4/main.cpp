#include "BoolMatrix.h"	

int main() {
	int n, m;
	cout << "Enter the number of rows: ";
	cin >> n;
	cout << "Enter the number of columns : " ;
	cin >> m;
	BoolMatrix M1(n, m);
	cout << endl << "First Matrix: " << endl;
	M1.PrintMatrix();

	BoolMatrix M2(M1);
	cout << endl << "Second Matrix: " << endl;
	M2.PrintMatrix();

	BoolMatrix M3 = M1 | M2;
	cout << endl << "Third Matrix: " << endl;
	M3.PrintMatrix();

	~M3;
	cout << endl << "Inversion third Matrix: " << endl;
	M3.PrintMatrix();

	cout << endl << "Number of Units = " << M3.NumberOfUnits() << endl;

	return 0;
}