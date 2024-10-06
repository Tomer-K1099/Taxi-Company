#include "Address.h"

// Constructor
Address::Address(int n, const std::string& s, const std::string& c)
    : num(n), street(s), city(c) {
    // No additional initialization required
}

// Comparison Operator
bool Address::operator==(const Address& other) const {
    return num == other.num &&
        street == other.street &&
        city == other.city;
}

// Output Stream Operator
std::ostream& operator<<(std::ostream& os, const Address& address) {
    os << "Number: " << address.getNum() << ", Street: " << address.getStreet()
        << ", City: " << address.getCity();
    return os;
}

// Getters
int Address::getNum() const {
    return num;
}

const std::string& Address::getStreet() const {
    return street;
}

const std::string& Address::getCity() const {
    return city;
}

// Setters
bool Address::setNum(int n) {
    num = n;
    return true;
}

bool Address::setStreet(const std::string& s) {
    street = s;
    return true;
}

bool Address::setCity(const std::string& c) {
    city = c;
    return true;
}

// Static Method to Parse an Address from a String
Address* Address::parseAddress(const std::string& addressStr) throw (std::string&) {
    // Simple parsing example: "123 Main St, Springfield"
    size_t numPos = addressStr.find_first_of("0123456789");
    size_t streetPos = addressStr.find_first_not_of("0123456789 ", numPos);
    size_t cityPos = addressStr.find_last_of(',');

    if (numPos == std::string::npos || streetPos == std::string::npos || cityPos == std::string::npos) {
        throw std::string("Invalid address format.");
    }

    int num = std::stoi(addressStr.substr(numPos, streetPos - numPos));
    std::string street = addressStr.substr(streetPos, cityPos - streetPos);
    std::string city = addressStr.substr(cityPos + 1);

    return new Address(num, street, city);
}


