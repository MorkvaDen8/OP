#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Array {
private:
	int size;
	T* data;
public:
	Array(int size);
	~Array();
	int GetSize();
	void PositionElement();
	void NewElement();
	void DeleteElement();
	class Iterator {
	private:
		int position;
		Array<T>* data;
	public:
		Iterator(Array<T>* data);
		void BeginArray();
		bool EndArray();
		T& ValueElement();
		void NextElement();
	};
	void ShowArray();
};

