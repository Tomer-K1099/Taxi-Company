#include "Driver.h"
#include "Ride.h"
#include <iostream>  // For strlen, strcpy

// Constructor
Driver::Driver( Taxi& taxi, const char* name, const char* id, const char* licenseNumber, int rideCount, Ride** rideArr) :
    Person(name, id), taxi(taxi), rideCount(rideCount) {
    setLicenseNumber(licenseNumber);
	rideArr = new Ride * [rideCount];
    for (int i = 0; i < rideCount; i++)
	    rideArr[i] = new Ride(*rideArr[i]);

}

// Copy Constructor
Driver::Driver(const Driver& other)
    : Person(other), rideCount(other.rideCount), taxi(other.taxi) {

           setLicenseNumber(other.licenseNumber);
           rideArr = new Ride * [rideCount];
           for (int i = 0; i < rideCount; i++)
               rideArr[i] = new Ride(*other.rideArr[i]);
       
       
}

// Move Constructor
Driver::Driver(Driver&& other)   : Person(other),rideCount(other.rideCount), taxi(other.taxi) {
    if (this != &other) {
        for (int i = 0; i < rideCount; i++)
			delete rideArr[i];
		delete[] rideArr;
        
        strcpy(licenseNumber, other.licenseNumber);
        for (int i = 0; i < other.rideCount; i++) {
            rideArr[i] = std::move(other.rideArr[i]);
            other.rideArr[i] = nullptr;
        }
        rideArr = std::move(other.rideArr);

    }
        // Nullify the moved-from object’s pointers
    other.rideArr = nullptr;
}

// Destructor
Driver::~Driver() {
    if(this->rideArr!=nullptr)
    {
        for (int i = 0; i < rideCount; i++)
            delete[] rideArr[i];
        delete[] rideArr;
    }
}

// Copy Assignment Operator
const Driver& Driver::operator=(const Driver& other) {
    if (this != &other) {
        Person::operator=(other);

        for (int i = 0; i < rideCount; i++)
            delete rideArr[i];
        delete[] rideArr;

        rideCount = other.rideCount;
        taxi = other.taxi;
        setLicenseNumber(other.licenseNumber);

		rideArr = new Ride * [other.rideCount];
		for (int i = 0; i < rideCount; i++)
			rideArr[i] = new Ride(*other.rideArr[i]);

    }
    return *this;
}

// Move Assignment Operator
const Driver& Driver::operator=(Driver&& other) {
    if (this != &other) {
        Person::operator=(std::move(other));

        for (int i = 0; i < rideCount; i++)
            delete[] rideArr[i];
        delete[] rideArr;

        rideCount = other.rideCount;
        taxi = other.taxi;

       

		rideArr = new Ride * [rideCount];
        for (int i = 0; i < other.rideCount; i++)        
            rideArr[i] = new Ride(std::move(*other.rideArr[i]));
        
        for (int i = 0; i < other.rideCount; i++)      
            delete[] other.rideArr;
    }
    return *this;
}

bool Driver::operator==(const Driver& other) const
{
	if (strcmp(licenseNumber, other.licenseNumber) == 0 && rideCount == other.rideCount && taxi == other.taxi)
        return true;
    return false;
}

// Getters
const char* Driver::getLicenseNumber() const {
    return licenseNumber;
}

const int Driver::getRideCount() const {
    return rideCount;
}

const Ride*const* Driver::getRide() const {
    return rideArr;
}

const Taxi& Driver::getTaxi() const {
    return taxi;
}

// Setters
bool Driver::setLicenseNumber(const char* licenseNumber) {
    
    if (licenseNumber == nullptr || strlen(licenseNumber) != LICENSE_NUMBER_SIZE) {
        return false;  // Invalid license number length
    }
    strcpy(this->licenseNumber, licenseNumber);
    return true;
}

bool Driver::setRide(Ride** ride, int size) {
        // Clean up the existing array if needed
        for (int i = 0; i < rideCount; ++i) {
            delete rideArr[i];
        }
        delete[] rideArr;
        
      
        rideArr = ride; // Point to the new array
        rideCount = size; // Update the ride count

        return true; // Return true indicating success
    }


bool Driver::setRideCount(int rideCount) {
    this->rideCount = rideCount;
    return true;
}

bool Driver::setTaxi(const Taxi& taxi) {
    this->taxi = taxi;
    return true;
}

Ride& Driver::addRide(Ride& ride)
{
    Ride** tempRideArr = new Ride * [rideCount + 1];
    for (int i = 0; i < rideCount; ++i) {
        tempRideArr[i] =  new Ride(*rideArr[i]);
    }
    tempRideArr[rideCount] = new Ride(ride); // Direct assignment
	setRide(tempRideArr, rideCount + 1);

    Ride& ret = *rideArr[rideCount-1];

    return ret;

}

//finds the price of a ride within the driver's ride array
double Driver::getRidePrice(Ride* pRide) {
    return pRide->getRidePrice();
}

std::ostream& operator<<(std::ostream& os, const Driver& driver)
{
	os << "Driver Name: " << driver.getName() << " ### Driver ID: " << driver.getId() << std::endl;

    os << "Driver Taxi: " << driver.getTaxi();
    os << " ### Driver Ride Count: " << driver.getRideCount() << std::endl;

	return os;
}
