#include <iostream>
#include <string>

class PhoneNumber {
private:
	std::string number;
public:
	PhoneNumber(std::string number);
	std::string GetNumber();
};