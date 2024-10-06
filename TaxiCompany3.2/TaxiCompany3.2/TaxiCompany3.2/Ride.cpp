#include "Ride.h"
#include "Address.h"
#include "Payment.h"
#include "Customer.h"
#include "Driver.h"
#include <iostream>
#include <string>

// Constructor
Ride::Ride(Driver& drv, Customer& cust, int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay)
    : driver(drv), customer(cust), rideID(id), numberOfPassengers(passengers), rideTime(time),
      originAddress(origin), destAddress(dest), payment(pay) {
    // Basic constructor initializing the members with provided values
}

// Copy constructor
Ride::Ride(const Ride& other)
    : driver(other.driver), customer(other.customer), rideID(other.rideID),
    numberOfPassengers(other.numberOfPassengers), rideTime(other.rideTime),
    originAddress(other.originAddress), destAddress(other.destAddress),
    payment(other.payment) {
    // This performs a shallow copy since Customer and Driver are references.
}

// Move constructor
Ride::Ride(Ride&& other) noexcept
    : rideID(other.rideID),
    numberOfPassengers(other.numberOfPassengers),
    rideTime(other.rideTime),
    originAddress(std::move(other.originAddress)),
    destAddress(std::move(other.destAddress)),
    payment(std::move(other.payment)),
    customer(other.customer), 
    driver(other.driver) {   
    other.rideID = 0;
    other.numberOfPassengers = 0;
    other.rideTime = 0;
}


// Assignment operator
Ride& Ride::operator=(const Ride& other) {
	if (this != &other) {
		rideID = other.rideID;
		numberOfPassengers = other.numberOfPassengers;
		rideTime = other.rideTime;
		originAddress = other.originAddress;
		destAddress = other.destAddress;
		payment = other.payment;
		customer = other.customer;  // References are simply reassigned
		driver = other.driver;      // References are simply reassigned
	}
	return *this;
}

Ride& Ride::operator=(Ride&& other) noexcept {
    if (this != &other) {
        rideID = other.rideID;
        numberOfPassengers = other.numberOfPassengers;
        rideTime = other.rideTime;
        originAddress = std::move(other.originAddress);
        destAddress = std::move(other.destAddress);
        payment = std::move(other.payment);
        customer = other.customer;  // References are simply reassigned
        driver = other.driver;      // References are simply reassigned

        // Optionally reset the moved-from object
        other.rideID = 0;
        other.numberOfPassengers = 0;
        other.rideTime = 0;
    }
    return *this;
}


// Overloaded << operator for printing Ride information
std::ostream& operator<<(std::ostream& os, const Ride& ride) {
    os << " ########## Ride ID: " << ride.getRideID()
       << " ########## Passengers: " << ride.getNumberOfPassengers()
       << " ########## Time: " << ride.getRideTime()
       << " ########## Origin: " << ride.getOriginAddress()
       << " ########## Destination: " << ride.getDestAddress()
       << " ########## Payment: " << ride.getPayment()
	   << " ########## Customer: " << ride.getCustomer().getName() << " Customer ID:" << ride.getCustomer().getId()
       << " ########## Driver: " << ride.getDriver().getName();
    return os;
}

// Getters
int Ride::getRideID() const {
    return rideID;
}

int Ride::getNumberOfPassengers() const {
    return numberOfPassengers;
}

int Ride::getRideTime() const {
    return rideTime;
}

const Address& Ride::getOriginAddress() const {
    return originAddress;
}

const Address& Ride::getDestAddress() const {
    return destAddress;
}

const Payment& Ride::getPayment() const {
    return payment;
}

const Customer& Ride::getCustomer() const {
    return customer;
}

const Driver& Ride::getDriver() const {
    return driver;
}

// Setters
bool Ride::setRideID(int id) {
    rideID = id;
    return true;
}

bool Ride::setNumberOfPassengers(int passengers) {
    if (passengers < 0) return false;  // Validate passenger count
    numberOfPassengers = passengers;
    return true;
}

bool Ride::setRideTime(int time) {
    if (time < 0) return false;  // Validate time
    rideTime = time;
    return true;
}

bool Ride::setOriginAddress(const Address& origin) {
    originAddress = origin;
    return true;
}

bool Ride::setDestAddress(const Address& dest) {
    destAddress = dest;
    return true;
}

bool Ride::setPayment(const Payment& pay) {
    payment = pay;
    return true;
}

// Method to calculate the ride price
double Ride::getRidePrice() {
    return getPayment().getPrice();
}
