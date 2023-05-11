#include "functions.h"

void BankAccount::ShowBankInfo() {
	cout << "Account number: " << number << endl;
	if (status) {
		cout << "Account status: Opened" << endl;
	}
	else {
		cout << "Account status: Closed" << endl;
	}
}

string BankAccount::GetName() {
	return name;
}
int BankAccount::GetNumber() {
	return number;
}
void BankAccount::SetName(string name) {
	this->name = name;
}
void BankAccount::SetNumber(int number) {
	this->number = number;
}
void BankAccount::SetStatus(bool status) {
	this->status = status;
}

void DepositAccount::SetAllValues() {
	cout << endl;
	cout << "Enter the deposit start date(Format: 20 01 2002): ";
	cin >> DataBegin[0] >> DataBegin[1] >> DataBegin[2];
	cout << "Enter the deposit period(in months) - ";
	cin >> period;
	cout << "Enter the deposit percentage - ";
	cin >> percent;
	cout << "Enter the deposit sum - ";
	cin >> sum;
	SetDataEndDeposit();
}

int* DepositAccount::GetDataBegin() {
	return DataBegin;
}

int DepositAccount::GetPeriod() {
	return period;
}

float DepositAccount::GetPercent() {
	return percent;
}

int DepositAccount::GetSum() {
	return sum;
}

void DepositAccount::SetDataEndDeposit() {
	DataEndDeposit[0] = DataBegin[0];
	DataEndDeposit[1] = (DataBegin[1] + period) % 12;
	DataEndDeposit[2] = DataBegin[2] + ((DataBegin[1] + period) / 12);
}

int* DepositAccount::GetDataEndDeposit() {
	return DataEndDeposit;
}

void DepositAccount::ShowInfo() {
	cout << "DataBegin: " << DataBegin[0] << " " << DataBegin[1] << " " << DataBegin[2] << endl;
	cout << "Period = " << period << " month" << endl;
	cout << "Percent = " << percent << "%" << endl;
	cout << "Sum = " << sum << endl;
}

void CurrentAccount::SetAllValues() {
	cout << "Enter the date of last operation(Format: 20 01 2002): ";
	cin >> DataLastOperation[0] >> DataLastOperation[1] >> DataLastOperation[2];
	cout << "Enter balance: ";
	cin >> balance;
	cout << endl;
}

void CurrentAccount::SetDataLastOperation(int day, int month, int year) {
	DataLastOperation[0] = day;
	DataLastOperation[1] = month;
	DataLastOperation[2] = year;
}

int* CurrentAccount::GetDataLastOperation() {
	return DataLastOperation;
}

void CurrentAccount::SetBalance(int balance) {
	this->balance = balance;
}

int CurrentAccount::GetBalance() {
	return balance;
}

void CurrentAccount::AddMoney() {
	int sum;
	cout << "Enter sum for add: ";
	cin >> sum;
	balance += sum;
}

void CurrentAccount::WithdrawMoney() {
	int sum;
	cout << "Enter sum for withdraw: ";
	cin >> sum;
	if (sum <= balance) {
		balance -= sum;
	}
	else {
		cout << "There are not enough money in the account!" << endl;
	}
}

void CurrentAccount::ShowInfo() {
	cout << "Data Last Operation: " << DataLastOperation[0] << " " << DataLastOperation[1] << " " << DataLastOperation[2] << endl;
	cout << "Balance = " << balance << endl;
}

bool Comparison(int data1[], int data2[]) {
	if (data2[2] > data1[2]) {
		return true;
	}
	else if (data2[2] == data1[2] && (data2[1] > data1[1] || (data2[1] == data1[1] && data2[0] >= data1[0]))) {
		return true;
	}
	else {
		return false;
	}
}

int DateDifference(int data1[], int data2[]) {
	int d, m, riz;
	if (data2[0] > data1[0]) {
		d = 1;
	}
	else {
		d = 0;
	}
	riz = ((data2[2] - data1[2]) * 12) + abs(data2[1] - data1[1]) + d;
	return riz;
}

void AccountsToday(int n, DepositAccount* array1, CurrentAccount* array2) {
	float endsum;
	int TodayDate[3];
	cout << "Enter today date(Format: 20 01 2002): ";
	cin >> TodayDate[0] >> TodayDate[1] >> TodayDate[2];
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (Comparison(array1[i].GetDataEndDeposit(), TodayDate)) {
			endsum = array1[i].GetSum() + (array1[i].GetSum() * ((array1[i].GetPercent() / 12) / 100 * array1[i].GetPeriod()));
			endsum += array2[i].GetBalance();
			array2[i].SetBalance(endsum);
			array1[i].SetStatus(false);
		}
		else {
			endsum = array1[i].GetSum() * (DateDifference(array1[i].GetDataBegin(), TodayDate) * (array1[i].GetPercent() / 12) / 100);
			endsum += array2[i].GetBalance();
			array2[i].SetBalance(endsum);
		}
	}
}

void OperationsWithMoney(CurrentAccount* array) {
	int vib,i,oper,day,month,year;
	cout << "Maybe you want Add/Withdraw money?(No-0, Yes-1): ";
	cin >> vib;
	cout << "Enter today date(Format: 20 01 2002): ";
	cin >> day >> month >> year;
	while (vib != 0) {
		cout << "Enter account number: ";
		cin >> i;
		array[i-1].SetDataLastOperation(day, month, year);
		cout << "1. Add Money" << endl << "2. Withdraw money" << endl << "Choose operation: ";
		cin >> oper;
		if (oper == 1) {
			array[i-1].AddMoney();
		}
		else if (oper == 2) {
			array[i-1].WithdrawMoney();
		}
		else {
			cout << "Incorrect operation!" << endl;
		}
		cout << "Maybe you want to do another operation?(No-0, Yes-1): ";
		cin >> vib;
	}
	cout << endl;
}