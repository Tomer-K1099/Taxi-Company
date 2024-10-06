#include "Customer.h"
#include <iostream>

// Constructor
Customer::Customer(const std::string& name, const std::string& id, const std::string& phoneNumber)
    : Person(name, id), phoneNumber(phoneNumber) {
    // Optionally, validate phone number length here
    if (phoneNumber.length() != PHONE_NUMBER_SIZE) {
        std::cerr << "Warning: Phone number length is incorrect." << std::endl;
    }
}

// Comparison Operator
bool Customer::operator==(const Customer& other) const {
    return (this->phoneNumber == other.phoneNumber) &&
        (this->getName() == other.getName()) &&
        (this->getId() == other.getId());
}

// Output Stream Operator
std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Customer Name: " << customer.getName() << std::endl;
    os << "Customer ID: " << customer.getId() << std::endl;
    os << "Phone Number: " << customer.getPhoneNumber() << std::endl;
    return os;
}

// Setter for Phone Number
bool Customer::setPhoneNumber(const std::string& phoneNumber) {
    if (phoneNumber.length() != PHONE_NUMBER_SIZE) {
        return false;  // Invalid phone number length
    }
    this->phoneNumber = phoneNumber;
    return true;
}

// Getter for Phone Number
const std::string& Customer::getPhoneNumber() const {
    return phoneNumber;
}

