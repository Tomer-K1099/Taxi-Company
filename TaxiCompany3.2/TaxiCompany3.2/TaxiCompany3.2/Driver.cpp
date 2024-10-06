#include "Driver.h"
#include "Ride.h"
#include <iostream>





// Constructor
Driver::Driver(Taxi& taxi, const std::string& name, const std::string& id,
    const std::string& licenseNumber, LinkedList<Ride> rideList)
    : Person(name, id), taxi(taxi), licenseNumber(licenseNumber), rideList(std::move(rideList)) {
    // No additional setup needed
}

 //Copy Assignment Operator
const Driver& Driver::operator=(const Driver& other) {
    if (this != &other) {
        Person::operator=(other);  // Copy base class data
		setTaxi(other.taxi);  // Copy Taxi data
        rideCount = other.rideCount;
        rideList = other.rideList;  // Copy LinkedList
        // licenseNumber is const, no need to reassign
    }
    return *this;
}


// Comparison Operator
bool Driver::operator==(const Driver& other) const {
    return (licenseNumber == other.licenseNumber && rideCount == other.rideCount && taxi == other.taxi);
}

// Getters
const std::string& Driver::getLicenseNumber() const {
    return licenseNumber.c_str();
}

const int Driver::getRideCount() const {
    return rideCount;
}


const Taxi& Driver::getTaxi() const {
    return taxi;
}

// Setters
bool Driver::setName(const std::string& name) {
    return Person::setName(name);  // Delegate to base class
}

bool Driver::setId(const std::string& id) {
    return Person::setId(id);  // Delegate to base class
}

bool Driver::setRideList(LinkedList<Ride> rideL, int size) {
    rideList = std::move(rideL);  // Assign the new ride list
    rideCount = size;
    return true;
}


bool Driver::setTaxi(const Taxi& taxi) {
    this->taxi =taxi;
    return true;
}
//Getters
const LinkedList<Ride>& Driver:: getRideList() const{
    return rideList;
}


double Driver::getRidePrice(Ride* pRide) {
    return pRide->getRidePrice();
}

// Overload the << operator to print Driver details
 std::ostream& operator<<(std::ostream& os, const Driver& driver) {
    os << "Driver Name: " << driver.getName() << std::endl;
    os << "Driver ID: " << driver.getId() << std::endl;
    os << "License Number: " << driver.getLicenseNumber() << std::endl;
    os << "Driver Ride Count: " << driver.getRideCount() << std::endl;
    os << "Driver Taxi: " << driver.getTaxi() << std::endl;
    os << driver.getName() <<"'s Rides: " << std::endl;
    driver.getRideList().print();
	os << "-----------------------------------------------" << std::endl;
    return os;

 }
    