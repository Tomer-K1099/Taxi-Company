#include "Minibus.h"
#include <iostream>

// Constructor
Minibus::Minibus(const std::string& vehicleNumber, const std::string& color)
    : Taxi(vehicleNumber, color, 15) {  // Set MaxPassengers to 15
}

std::string Minibus::getType() const {
    return "Minibus";
}
