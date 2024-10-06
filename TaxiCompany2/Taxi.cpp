#include "Taxi.h"
#include <cstring>  // For strlen, strcpy

// Constructor
Taxi::Taxi(const char* vehicleNumber, const char* color, int maxPassengers)
    : maxPassengers(maxPassengers) {  // Initialize const member
    strcpy(this->vehicleNumber, vehicleNumber);
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
}

// Copy Constructor
Taxi::Taxi(const Taxi& other)
    : maxPassengers(other.maxPassengers) {  // Copy const member
    strcpy(this->vehicleNumber, other.vehicleNumber);
    this->color = new char[strlen(other.color) + 1];
    strcpy(this->color, other.color);
}

// Move Constructor
Taxi::Taxi(Taxi&& other) : maxPassengers(other.maxPassengers) {  // Move const member
    if (this != &other) {
        if (color)
            delete[] color;

        strcpy(this->vehicleNumber, other.vehicleNumber);

        color = new char[strlen(other.color) + 1];
        strcpy(color, other.color);
    }

    other.color = nullptr;
}


Taxi& Taxi::operator=(const Taxi& other) {
    if (this != &other) {
        // Check if the name pointer is valid or needs to be reallocated
        if (color) {
            delete[] color;

            color = new char[strlen(other.color) + 1];
            strcpy(color, other.color);
        }
    }
    return *this;
}
// Move Assignment Operator
Taxi& Taxi::operator=(Taxi&& other) noexcept {
    if (this != &other) {
        if (color != nullptr) {
            delete[] color;
            color = nullptr;
        }
		if (other.color != nullptr)
		{
			color = new char[strlen(other.color) + 1];
			strcpy(color, other.color);
		}
        else
			color = nullptr;


        strcpy(this->vehicleNumber, other.vehicleNumber);
        other.color = nullptr;
    }
    return *this;
}

//Destructor
Taxi::~Taxi() {
	delete[] color;
}

bool Taxi::operator==(const Taxi& other) const
{
	if (strcmp(vehicleNumber, other.vehicleNumber) == 0 && strcmp(color, other.color) == 0 && maxPassengers == other.maxPassengers)
		return true;
    return false;
}


// Getters
const char* Taxi::getVehicleNumber() const {
    return vehicleNumber;
}

const char* Taxi::getColor() const {
    return color;
}

const int Taxi::getMaxPassengers() const {
    return maxPassengers;
}


// Setters
bool Taxi::setVehicleNumber(const char* vehicleNumber) {
    if (strlen(vehicleNumber) != VEHICLE_NUMBER_SIZE) {
        return false;  // Invalid vehicle number length
    }
    strcpy(this->vehicleNumber, vehicleNumber);
    return true;
}

bool Taxi::setColor(const char* color) {
    delete[] this->color;
    this->color = new char[strlen(color) + 1];
    strcpy(this->color, color);
    return true;
}
const Taxi* Taxi::findTaxiByTaxiNumber(char* vehicleNumber, const Taxi** taxiArr, int count) const
{
    for (int i = 0; i < count; i++) {
        if (strcmp(taxiArr[i]->getVehicleNumber(), vehicleNumber) == 0) {
            return taxiArr[i];
        }
    }
    return nullptr;
}
std::ostream& operator<<(std::ostream& os, const Taxi& taxi) {
    os << "Type: " << taxi.getType() << " ### Vehicle Number: " << taxi.getVehicleNumber()
        << " ### Color: " << taxi.getColor() << " ### Max Passengers: " << taxi.getMaxPassengers() << std::endl;
    return os;
}   


