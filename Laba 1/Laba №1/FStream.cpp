#include "FStream.h"

int menuS() {
	int choice;
	cout << endl;
	cout << "1.Write to File" << endl;
	cout << "2 Read File" << endl;
	cout << "3. Add File" << endl;
	cout << "4 Sort File" << endl;
	cout << "0. Exit" << endl;
	cout << "Choose operation: ";
	cin >> choice;
	return choice;
}

string GetFilenameS() {
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	return filename;
}

void WriteToFileS(string filename) {
	int n;
	string stroka;
	ofstream file(filename);
	if (!file) {
		cout << "File opening error!" << endl;
		return;
	}
	cout << "Enter number rows: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, stroka);
		file << stroka;
		file << endl;
	}
	file.close();
}

void ReadFileS(string filename) {
	string stroka;
	ifstream file(filename);
	if (!file) {
		cout << "File opening error!" << endl;
		return;
	}
	while (getline(file, stroka)) {
		cout << stroka << endl;
	}
	file.close();
}

void AddToFileS(string filename) {
	string stroka;
	ofstream file(filename, ios::app);
	if (!file) {
		cout << "File opening error!" << endl;
		return;
	}
	cout << "Enter text line for add to file: ";
	cin.ignore();
	getline(cin, stroka);
	file << stroka;
	file << endl;
	file.close();
}

string DublicateS(string stroka) {
	string newstroka;
	int n = stroka.length();
	int count = 1;

	for (int i = 1; i < n; i++) {
		if (stroka[i] == stroka[i - 1]) {
			count++;
		}
		else {
			if (count > 1) {
				newstroka += '(' + to_string(stroka[i - 1] - '0') + ')';
			}
			else {
				newstroka += stroka[i - 1];
			}
			count = 1;
		}
	}

	if (count > 1) {
		newstroka += '(' + to_string(stroka[n - 1] - '0') + ')';
	}
	else {
		newstroka += stroka[n - 1];
	}

	return newstroka;
}

string SortStringS(string stroka) {
	int n = stroka.length();
	string newstroka, word, numbers;
	for (int i = 0; i < n; i++)
		if (isdigit(stroka[i])) {
			numbers += stroka[i];
		}
	stroka.erase(remove_if(stroka.begin(), stroka.end(), isdigit), stroka.end());

	int strokabegin = 0, strokaend = stroka.length() - 1;

	while (strokabegin < strokaend) {
		swap(stroka[strokabegin], stroka[strokaend]);
		strokabegin++;
		strokaend--;
	}

	numbers = DublicateS(numbers);
	newstroka = numbers + stroka;
	return newstroka;
}

void SortFileS(string filename) {
	string stroka, fileout;
	ifstream file(filename);
	if (!file) {
		cout << "File opening error!" << endl;
		return;
	}
	cout << "Enter name of other file(text2.txt): ";
	cin >> fileout;
	ofstream file2(fileout);
	while (getline(file, stroka)) {
		cout << SortStringS(stroka) << endl;
		file2 << SortStringS(stroka) << endl;
	}
	file.close();
	file2.close();
}
