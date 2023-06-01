#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(std::string number) {
	this->number = number;
}

std::string PhoneNumber::GetNumber() {
	return number;
}