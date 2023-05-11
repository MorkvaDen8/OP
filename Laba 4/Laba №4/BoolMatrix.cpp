#include "BoolMatrix.h"

BoolMatrix::BoolMatrix() {
	n = 0;
	m = 0;
	arr = 0;
}

BoolMatrix::BoolMatrix(int n, int m) {
	this->n = n;
	this->m = m;
	this->arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 2;
		}
	}
}

BoolMatrix::BoolMatrix(const BoolMatrix& other) {
	this->n = other.n;
	this->m = other.m;
	this->arr = new int* [other.n];

	for (int i = 0; i < other.n; i++) {
		this->arr[i] = new int[other.m];
	}

	for (int i = 0; i < other.n; i++) {
		for (int j = 0; j < other.m; j++) {
			this->arr[i][j] = other.arr[i][j];
		}
	}
}

int BoolMatrix::GetN() {
	return n;
}
int BoolMatrix::GetM() {
	return m;
}

BoolMatrix BoolMatrix::operator |(const BoolMatrix& other) {
	BoolMatrix temp;
	temp.n = other.n;
	temp.m = other.m;
	temp.arr = new int* [other.n];

	for (int i = 0; i < other.n; i++) {
		temp.arr[i] = new int[other.m];
	}

	for (int i = 0; i < other.n; i++) {
		for (int j = 0; j < other.m; j++) {
			if (this->arr[i][j] == 0 && other.arr[i][j] == 0) {
				temp.arr[i][j] = 0;
			}
			else {
				temp.arr[i][j] = 1;
			}
		}
	}
	return temp;
	
}

BoolMatrix BoolMatrix::operator ~() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (this->arr[i][j] == 0) {
				this->arr[i][j] = 1;
			}
			else {
				this->arr[i][j] = 0;
			}
		}
	}
	return *this;
}

void BoolMatrix :: PrintMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int BoolMatrix :: NumberOfUnits() {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (this->arr[i][j] == 1) {
				k++;
			}
		}
	}
	return k;
}

BoolMatrix ::~BoolMatrix() {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}