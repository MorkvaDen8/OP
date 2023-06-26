#include "class.h"

template <typename T>
Array<T>::Array(int size) {
	this->size = size;
	data = new T[size];
	for (int i = 0; i < size; i++) {
		cout << "Enter element " << i << ": ";
		cin >> data[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] data;
}

template <typename T>
int Array<T>::GetSize() {
	return size;
}

template <typename T>
void Array<T>::PositionElement() {
	bool available = 0;
	int index;
	T value{};

	cout << "Enter value: ";
	cin >> value;

	for (int i = 0; i < size; i++) {
		if (data[i] == value) {
			available = 1;
			index = i;
		}
	}

	if (available == 1) {
		cout << "The index of the searched value = " << index << endl;
	}
	else {
		cout << "This value does not exist in the array!" << endl;
	}
}

template <typename T>
void Array<T>::NewElement() {
	T value;
	int index;

	cout << "Enter value: ";
	cin >> value;
	cout << "Enter index: ";
	cin >> index;

	if (index < size) {
		data[index] = value;
	}

	else if (index == size) {
		size += 1;
		T* newData = new T[size];

		for (int i = 0; i < size - 1; i++) {
			newData[i] = data[i];
		}

		newData[index] = value;
		delete[] data;
		data = newData;
	}

	else {
		cout << "Your index is outside the array!" << endl;
	}
}

template <typename T>
void Array<T>::DeleteElement() {
	int index;
	cout << "Enter index: ";
	cin >> index;
	if (index >= 0 && index < size) {
		for (int i = index; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size = size - 1;
	}
	else {
		cout << "Your index is outside the array!" << endl;
	}

}

template <typename T>
Array<T>::Iterator::Iterator(Array<T>* data) {
	this->data = data;
}

template <typename T>
void Array<T>::Iterator::BeginArray() {
	position = 0;
};

template <typename T>
bool Array<T>::Iterator::EndArray() {
	if (position < data->GetSize()) {
		return true;
	}
	else {
		return false;
	}
}

template <typename T>
T& Array<T>::Iterator::ValueElement() {
	return data->data[position];
}

template <typename T>
void Array<T>::Iterator::NextElement() {
	position++;
}

template <typename T>
int Array<T>::Iterator::GetPosition() {
	return position;
}

template <typename T>
void Array<T>::ShowArray() {
	Iterator it(this);
	cout << "Array: ";
	it.BeginArray();
	while (it.EndArray()) {
		cout << it.ValueElement() << " ";
		it.NextElement();
	}
	cout << endl;
}


