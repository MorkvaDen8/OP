#include "functions.h"

int main() {
	int size, type, choice = 1;
	cout << "Enter size of array: ";
	cin >> size;
	type = ArrayType();

	if (type == 1) {
		menu1(size);
	}
	else if (type == 2) {
		menu2(size);
	}

	else if(type == 3){
		menu3(size);
	}
	return 0;
}