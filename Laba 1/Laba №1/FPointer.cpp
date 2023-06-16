#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int menuP() {
    int choice;
    cout << "1. Write to File" << endl;
    cout << "2. Read File" << endl;
    cout << "3. Add File" << endl;
    cout << "4. Sort File" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose operation: ";
    cin >> choice;
    return choice;
}

char* GetFilenameP() {
    char* filename = new char[100];
    cout << "Enter filename: ";
    cin.getline(filename, 100);
    return filename;
}

void WriteToFileP(char* filename) {
    FILE* file = fopen(filename, "w");
    int n;
    char stroka[100];
    if (!file) {
        cout << "File opening error!" << endl;
        return;
    }
    cout << "Enter number of rows: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin.getline(stroka, 100);
        fputs(stroka, file);
        fputc('\n', file);
    }
    fclose(file);
}

void ReadFileP(char* filename) {
    FILE* file = fopen(filename, "r");
    char stroka[100];
    if (!file) {
        cout << "File opening error!" << endl;
        return;
    }
    while (fgets(stroka, 100, file) != NULL) {
        cout << stroka;
    }
    fclose(file);
}

void AddToFileP(char* filename) {
    FILE* file = fopen(filename, "a");
    char stroka[100];
    if (!file) {
        cout << "File opening error!" << endl;
        return;
    }
    cout << "Enter text line to add to the file: ";
    cin.ignore();
    cin.getline(stroka, 100);
    fputs(stroka, file);
    fputc('\n', file);
    fclose(file);
}

char* DublicateP(char* stroka) {
    char* newstroka = new char[100];
    int n = strlen(stroka);
    int count = 1;
    int newstrokaIndex = 0;

    for (int i = 1; i < n; i++) {
        if (stroka[i] == stroka[i - 1]) {
            count++;
        }
        else {
            if (count > 1) {
                newstroka[newstrokaIndex++] = '(';
                newstroka[newstrokaIndex++] = stroka[i - 1];
                newstroka[newstrokaIndex++] = ')';
            }
            else {
                newstroka[newstrokaIndex++] = stroka[i - 1];
            }
            count = 1;
        }
    }

    if (count > 1) {
        newstroka[newstrokaIndex++] = '(';
        newstroka[newstrokaIndex++] = stroka[n - 1];
        newstroka[newstrokaIndex++] = ')';
    }
    else {
        newstroka[newstrokaIndex++] = stroka[n - 1];
    }
    newstroka[newstrokaIndex] = '\0';

    return newstroka;
}

char* SortStringP(char* stroka) {
    int n = strlen(stroka);
    char* newstroka = new char[200];
    char numbers[100];
    int numbersIndex = 0;
    int newstrokaIndex = 0;

    for (int i = 0; i < n; i++) {
        if (isdigit(stroka[i])) {
            numbers[numbersIndex++] = stroka[i];
        }
    }
    numbers[numbersIndex] = '\0';

    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(stroka[i])) {
            newstroka[newstrokaIndex++] = stroka[i];
        }
    }
    newstroka[newstrokaIndex] = '\0';

    char* duplicatedNumbers = DublicateP(numbers);
    strcat(duplicatedNumbers, newstroka);
    strcpy(newstroka, duplicatedNumbers);
    delete[] duplicatedNumbers;

    return newstroka;
}

void SortFileP(char* filename) {
    FILE* file = fopen(filename, "r");
    char stroka[100];
    if (!file) {
        cout << "File opening error!" << endl;
        return;
    }
    while (fgets(stroka, 100, file) != NULL) {
        char* sortedStroka = SortStringP(stroka);
        cout << sortedStroka;
        delete[] sortedStroka;
    }
    fclose(file);
}

