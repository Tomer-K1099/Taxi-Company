#include "Minibus.h"
#include <iostream>

// Constructor
Minibus::Minibus(const char* vehicleNumber, const char* color)
    : Taxi(vehicleNumber, color, 15) {  // Set MaxPassengers to 15
}


const char* Minibus::getType() const {
    return "Minibus";
}
