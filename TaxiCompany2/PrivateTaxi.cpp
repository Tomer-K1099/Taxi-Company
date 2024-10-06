#include "PrivateTaxi.h"
#include <iostream>

// Constructor
PrivateTaxi::PrivateTaxi(const char* vehicleNumber, const char* color)
    : Taxi(vehicleNumber, color, 5) {  // Set MaxPassengers to 5
}

const char* PrivateTaxi::getType() const {
    return "Private Taxi";
}
