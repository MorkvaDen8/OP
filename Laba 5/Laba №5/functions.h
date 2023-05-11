#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
	string name;
	int number;
	bool status = 1;
	virtual void AddMoney() {};
	virtual void WithdrawMoney() {};

public:
	string GetName();
	int GetNumber();
	void ShowBankInfo();
	void SetName(string name);
	void SetNumber(int number);
	void SetStatus(bool status);
};

class DepositAccount : public BankAccount { //Депозитний рах.
private:
	int DataBegin[3];
	int period;
	float percent;
	int sum;
	int DataEndDeposit[3];
public:
	void SetAllValues();
	int* GetDataBegin();
	int GetPeriod();
	float GetPercent();
	int GetSum();
	void SetDataEndDeposit();
	int* GetDataEndDeposit();
	void ShowInfo();
};

class CurrentAccount : public BankAccount { //Розрахунковий рах.
private:
	int DataLastOperation[3];
	int balance;
public:
	void SetAllValues();
	void SetDataLastOperation(int day, int month, int year);
	int* GetDataLastOperation();
	void SetBalance(int balance);
	int GetBalance();
	void AddMoney() override;
	void WithdrawMoney() override;
	void ShowInfo();
};

bool Comparison(int data1[], int data2[]);
int DateDifference(int data1[], int data2[]);
void AccountsToday(int n, DepositAccount* array1, CurrentAccount* array2);
void OperationsWithMoney(CurrentAccount* array);
