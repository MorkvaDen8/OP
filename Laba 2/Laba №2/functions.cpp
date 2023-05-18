#include "functions.h"

int menu() {
	int n;
	cout << endl;
	cout << "1. Write to File" << endl;
	cout << "2. Read File" << endl;
	cout << "3. Add to File" << endl;
	cout << "4. Expired products(to another file)" << endl;
	cout << "5. Produced in the last 10 days" << endl;
	cout << "0. Exit" << endl;
	cout << "Enter you choice: ";
	cin >> n;
	cout << endl;
	return n;
}

void WriteToFile(string filename) {
	Product product;
	int n;
	cout << "Enter the number of products(n): ";
	cin >> n;
	ofstream file(filename, ios::binary);
	if (!file) {
		cout << "Error opening file!" << endl;
		return;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cin.ignore();
		cout << "Enter product name: ";
		getline(cin, product.name);
		cout << "Enter data begin: ";
		cin >> product.dataBegin[0] >> product.dataBegin[1] >> product.dataBegin[2];
		cout << "Enter data end: ";
		cin >> product.dataEnd[0] >> product.dataEnd[1] >> product.dataEnd[2];
		cout << "Enter product price: ";
		cin >> product.price;
		cout << endl;
		file.write((char*)&product, sizeof(Product));
	}
	file.close();
}

void ReadFile(string filename) {
	ifstream file(filename, ios::binary);
	if (!file) {
		cout << "Error opening file!" << endl;
		return;
	}
	file.seekg(0, ios::end);
	int count = file.tellg() / sizeof(Product);
	file.seekg(0, ios::beg);
	Product* product = new Product[count];

	for (int i = 0; i < count; ++i) {
		file.read(reinterpret_cast<char*>(&product[i]), sizeof(Product));
		cout << "Name: " << product[i].name << endl;
		cout << "Release date: " << product[i].dataBegin[0] << " " << product[i].dataBegin[1] << " " << product[i].dataBegin[2] << endl;
		cout << "Expiry date: " << product[i].dataEnd[0] << " " << product[i].dataEnd[1] << " " << product[i].dataEnd[2] << endl;
		cout << "Price: " << product[i].price << endl << endl;
	}
	file.close();
}

void AddToFile(string filename) {
	Product product;
	ofstream file(filename, ios::binary | ios::app);
	if (!file) {
		cout << "Error opening file!" << endl;
		return;
	}
	cin.ignore();
	cout << "Enter product name: ";
	getline(cin, product.name);
	cout << "Enter data begin: ";
	cin >> product.dataBegin[0] >> product.dataBegin[1] >> product.dataBegin[2];
	cout << "Enter data end: ";
	cin >> product.dataEnd[0] >> product.dataEnd[1] >> product.dataEnd[2];
	cout << "Enter product price: ";
	cin >> product.price;
	cout << endl;
	file.write((char*)&product, sizeof(Product));
	file.close();
}

int DaysBetweenDates(int* date1, int* date2) {
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;

	if (date1[1] == date2[1] && date1[2] == date2[2]) {
		return date2[0] - date1[0];
	}

	days += daysInMonth[date1[1] - 1] - date1[0];
	for (int month = date1[1] + 1; month < date2[1]; ++month) {
		days += daysInMonth[month - 1];
	}

	days += date2[0];
	int startYear = date1[2];
	int endYear = date2[2];

	for (int year = startYear; year < endYear; ++year) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			days += 366;  
		}
		else {
			days += 365;
		}
	}
	return days;
}

void ExpirationDate(string filename, int* todayDate) {
	int TodayDate[3], SumTermin, TerminToEnd;
	float riz;
	string filename2;

	ifstream file(filename, ios::binary);
	if (!file) {
		cout << "Error opening file!" << endl;
		return;
	}
	file.seekg(0, ios::end);
	int count = file.tellg() / sizeof(Product);
	file.seekg(0, ios::beg);
	Product* product = new Product[count];

	cout << "Enter output name of file: ";
	cin >> filename2;

	ofstream file2(filename2, ios::binary);
	if (!file2) {
		cout << "Error opening file!" << endl;
		return;
	}

	for (int i = 0; i < count; ++i) {
		file.read(reinterpret_cast<char*>(&product[i]), sizeof(Product));
		SumTermin = DaysBetweenDates(product[i].dataBegin, product[i].dataEnd);
		TerminToEnd = DaysBetweenDates(todayDate, product[i].dataEnd);
		riz = (float)TerminToEnd / (float)SumTermin;
		if (riz <= 0.1) {
			file2.write((char*)&product[i], sizeof(Product));
		}
	}
	file.close();
	file2.close();
	ReadFile(filename2);
}

void TenDays(string filename, int* todayDate) {
	int riz;
	ifstream file(filename, ios::binary);
	if (!file) {
		cout << "Error opening file!" << endl;
		return;
	}
	file.seekg(0, ios::end);
	int count = file.tellg() / sizeof(Product);
	file.seekg(0, ios::beg);
	Product* product = new Product[count];
	cout << "Products produced in the last 10 days:" << endl;
	for (int i = 0; i < count; ++i) {
		file.read(reinterpret_cast<char*>(&product[i]), sizeof(Product));
		riz = DaysBetweenDates(product[i].dataBegin, todayDate);
		if (riz <= 10) {
			cout << "Name: " << product[i].name << endl;
			cout << "Release date: " << product[i].dataBegin[0] << " " << product[i].dataBegin[1] << " " << product[i].dataBegin[2] << endl;
			cout << "Expiry date: " << product[i].dataEnd[0] << " " << product[i].dataEnd[1] << " " << product[i].dataEnd[2] << endl;
			cout << "Price: " << product[i].price << endl << endl;
		}
	}
	file.close();
}