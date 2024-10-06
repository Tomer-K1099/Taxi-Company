#include "PrivateTaxi.h"
#include <iostream>
#include <string>

// Constructor
PrivateTaxi::PrivateTaxi(const std::string& vehicleNumber, const std::string& color)
    : Taxi(vehicleNumber, color, 5) {  // Set MaxPassengers to 5
}

std::string PrivateTaxi::getType() const {
    return "Private Taxi";
}
