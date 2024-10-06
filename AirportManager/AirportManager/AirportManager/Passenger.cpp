#ifndef _PASSENGER_CPP
#define _PASSENGER_CPP
// Passenger.cpp
#include "Passenger.h"
#include <iostream>
#include <cstring>

Passenger::Passenger(const char* name, int age, const char* gender, const char* address, const char* phoneNumber,
    int passengerID, const char* ticketNumber, const char* flightNumber)
    : Person(name, age, gender, address, phoneNumber), passengerID(passengerID) {
    this->ticketNumber = allocateAndCopy(ticketNumber);
    this->flightNumber = allocateAndCopy(flightNumber);
}

Passenger::Passenger(const Passenger& other)
    : Person(other), passengerID(other.passengerID) {
    ticketNumber = allocateAndCopy(other.ticketNumber);
    flightNumber = allocateAndCopy(other.flightNumber);
}

Passenger::~Passenger() {
    delete[] ticketNumber;
    delete[] flightNumber;
}

Passenger& Passenger::operator=(const Passenger& other) {
    if (this == &other) return *this; // Self-assignment check

    Person::operator=(other); // Assign base class parts
    delete[] ticketNumber;
    delete[] flightNumber;

    // Allocate new resources and copy
    passengerID = other.passengerID;
    ticketNumber = allocateAndCopy(other.ticketNumber);
    flightNumber = allocateAndCopy(other.flightNumber);

    return *this;
}

int Passenger::getPassengerID() const {
    return passengerID;
}

void Passenger::setPassengerID(int passengerID) {
    this->passengerID = passengerID;
}

const char* Passenger::getTicketNumber() const {
    return ticketNumber;
}

void Passenger::setTicketNumber(const char* ticketNumber) {
    delete[] this->ticketNumber;
    this->ticketNumber = allocateAndCopy(ticketNumber);
}

const char* Passenger::getFlightNumber() const {
    return flightNumber;
}

void Passenger::setFlightNumber(const char* flightNumber) {
    delete[] this->flightNumber;
    this->flightNumber = allocateAndCopy(flightNumber);
}

void Passenger::display() const {
    Person::display();
    std::cout << "Passenger ID: " << passengerID << std::endl;
    std::cout << "Ticket Number: " << ticketNumber << std::endl;
    std::cout << "Flight Number: " << flightNumber << std::endl;
}

#endif // !1
