#include "functions.h"

int main() {
	int TodayDate[3], choice;
	string filename;

	cout << "Enter today date: ";
	cin >> TodayDate[0] >> TodayDate[1] >> TodayDate[2];
	cout << "Enter name of file(Format - text.bin): ";
	cin >> filename;

	while (true) {
		choice = menu();
		switch (choice) {
		case 1:
			WriteToFile(filename);
			break;
		case 2:
			ReadFile(filename);
			break;
		case 3:
			AddToFile(filename);
			break;
		case 4:
			ExpirationDate(filename, TodayDate);
			break;
		case 5:
			TenDays(filename, TodayDate);
			break;
		case 0:
			return 0;
		default:
			cout << "Incorrect choice!" << endl;
			break;
		}
	}
}