#include "Ride.h"
#include "Address.h"
#include "Payment.h"
#include "Customer.h"
#include "Driver.h"

// Constructor
Ride::Ride( Driver& drv,  Customer& cust, int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay)
    : driver((drv)), rideID(id), numberOfPassengers(passengers), rideTime(time), originAddress(origin),
    destAddress(dest), payment(pay), customer((cust)) {
  
}

 //Copy Constructor
Ride::Ride(const Ride& other)
    : rideID(other.rideID),
    numberOfPassengers(other.numberOfPassengers),
    rideTime(other.rideTime),
    originAddress(other.originAddress),
    destAddress(other.destAddress),
    payment(other.payment),
    customer(other.customer),
    driver(other.driver) {
}

// Move Constructor
Ride::Ride(Ride&& other) noexcept
    : rideID(other.rideID), numberOfPassengers(other.numberOfPassengers), rideTime(other.rideTime),
    originAddress(std::move(other.originAddress)), destAddress(std::move(other.destAddress)),
    payment(std::move(other.payment)), customer(other.customer), driver(other.driver) {
    other.rideID = 0;
    other.numberOfPassengers = 0;
    other.rideTime = 0;
    
}

// Copy Assignment Operator
Ride& Ride::operator=(const Ride& other) {
    if (this != &other) { // Prevent self-assignment
        this->rideID = other.rideID;
        this->numberOfPassengers = other.numberOfPassengers;
        this->rideTime = other.rideTime;
        this->originAddress = other.originAddress;
        this->destAddress = other.destAddress;
        this->payment = other.payment;
        this->customer = other.customer;
        this->driver = other.driver;
    }
    return *this;
}
Ride& Ride::operator=(Ride&& other)
{
    if (this != &other) { 
        rideID = other.rideID;
        numberOfPassengers = other.numberOfPassengers;
        rideTime = other.rideTime;
        originAddress = std::move(other.originAddress);
        destAddress = std::move(other.destAddress);
        payment = std::move(other.payment);
        this->customer = other.customer;
        this->driver = other.driver;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Ride& ride) {
    os << " ### Ride ID : " << ride.getRideID() << " ### Passengers: " << ride.getNumberOfPassengers() << " ### Time: " << ride.getRideTime() << std::endl;
    os << "Origin: " << ride.getOriginAddress() << std::endl;
      os  << "Destination: " << ride.getDestAddress() << std::endl;
     os   << "Payment: " << ride.getPayment() << std::endl;
     os   << "Customer: " << ride.getCustomer().getName() << std::endl;
     os   << "Driver: " << ride.getDriver().getName() << std::endl;
    return os;
}

// Getters
const int Ride::getRideID() const {
    return rideID;
}

const int Ride::getNumberOfPassengers() const {
    return numberOfPassengers;
}

const int Ride::getRideTime() const {
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

double Ride::getRidePrice() {
    return getPayment().getPrice();
}

// Destructor
Ride::~Ride() {
}

