#include "Taxi.h"
#include <iostream>

// Constructor
Taxi::Taxi(const std::string& vehicleNumber, const std::string& color, const int maxPassengers)
    : vehicleNumber(vehicleNumber), color(color), maxPassengers(maxPassengers) {
   
}


// Copy Assignment Operator
Taxi& Taxi::operator=(const Taxi& other) {
    if (this != &other) {
        color = other.color;
    }
    return *this;
}
//

// Equality Operator
bool Taxi::operator==(const Taxi& other) const {
    return vehicleNumber == other.vehicleNumber &&
        color == other.color &&
        maxPassengers == other.maxPassengers;
}

// Getters
const std::string& Taxi::getVehicleNumber() const {
    return vehicleNumber;
}

const std::string& Taxi::getColor() const {
    return color;
}

const int Taxi::getMaxPassengers() const {
    return maxPassengers;
}

// Setters

bool Taxi::setColor(const std::string& color) {
    this->color = color;
    return true;
}

// Output Stream Operator
std::ostream& operator<<(std::ostream& os, const Taxi& taxi) {
    os << "Vehicle Number: " << taxi.getVehicleNumber() << std::endl;
    os << "Color: " << taxi.getColor() << std::endl;
    os << "Max Passengers: " << taxi.getMaxPassengers() << std::endl;
    os << "Type: " << taxi.getType() << std::endl;  // Calls the derived class's implementation
    return os;
}

// Find Taxi by Vehicle Number
const Taxi* Taxi::findTaxiByTaxiNumber(std::string& vehicleNumber, const Taxi** taxiArr, int count) const {
    for (int i = 0; i < count; i++) {
        if (taxiArr[i]->getVehicleNumber() == vehicleNumber) {
            return taxiArr[i];
        }
    }
    return nullptr;  // Not found
}


