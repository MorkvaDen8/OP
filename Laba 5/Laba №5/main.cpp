#include "functions.h"

int main() {
	int n;
	string name;
	cout << "Enter the number of accounts: ";
	cin >> n;
	DepositAccount* array1 = new DepositAccount[n]; //Депозитний рах.
	CurrentAccount* array2 = new CurrentAccount[n]; //Розрахунковий рах.
	cout << "Enter the Bank name: ";
	cin >> name;
	for (int i = 0; i < n; i++) {
		array1[i].SetName(name);
		array1[i].SetNumber(i + 1);
		array1[i].SetAllValues();
		array2[i].SetAllValues();
	}

	AccountsToday(n, array1, array2);
	cout << "Bank Name: " << array1[0].GetName() << endl;
	for (int i = 0; i < n; i++) {
		array1[i].ShowBankInfo();
		array1[i].ShowInfo();
		array2[i].ShowInfo();
		cout << endl;
	}

	OperationsWithMoney(array2);
	for (int i = 0; i < n; i++) {
		cout << "Account number: " << array2[i].GetNumber() << endl;
		array2[i].ShowInfo();
		cout << endl;
	}

	delete[] array1;
	delete[] array2;
	return 0;
}
