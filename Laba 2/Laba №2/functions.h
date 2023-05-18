#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

struct Product {
	string name;
	int dataBegin[3];
	int dataEnd[3];
	float price;
};

int menu();
void WriteToFile(string filename);
void ReadFile(string filaname);
void AddToFile(string filename);
int DaysBetweenDates(int* date1, int* date2);
void ExpirationDate(string filename, int* todayDate);
void TenDays(string filename, int* todayDate);