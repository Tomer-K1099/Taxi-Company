#include "Customer.h"
#include <cstring>  // For strlen, strcpy

// Constructor
Customer::Customer(const char* name, const char* id, const char* phoneNumber) : Person(name, id) {
    setPhoneNumber(phoneNumber);
}

bool Customer::operator==(const Customer& other) const {
    return (strcmp(this->getName(), other.getName()) == 0 &&
        strcmp(this->getId(), other.getId()) == 0 &&
        strcmp(this->getPhoneNumber(), other.getPhoneNumber()) == 0);
}


// Getters
const char* Customer::getPhoneNumber() const {
    return phoneNumber;
}


// Setters
bool Customer::setPhoneNumber(const char* phoneNumber) {
    if (strlen(phoneNumber) != PHONE_NUMBER_SIZE) {
        return false;  // Invalid phone number length
    }
    strcpy(this->phoneNumber, phoneNumber);
    return true;
}

std::ostream& operator<<(std::ostream& os, const Customer& customer)
{
	os << "Name: " << customer.getName();
    os << " ### ID: " << customer.getId();
    os << " ### Phone Number: " << customer.getPhoneNumber() << std::endl;
	return os;
}
