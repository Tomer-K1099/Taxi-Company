#ifndef _COMMERCIALPLANE_CPP
#define _COMMERCIALPLANE_CPP
#include "CommercialPlane.h"


CommercialPlane::CommercialPlane(int weightCapacity, int currentWeight, int fuelAmount, const char* model, State state,
    int numOfSeats, int actualSeatsOccupied, int totalBaggageWeight)
    : Airplane(weightCapacity, currentWeight, fuelAmount, model, state),
    numOfSeats(numOfSeats), actualSeatsOccupied(actualSeatsOccupied), totalBaggageWeight(totalBaggageWeight) {}

CommercialPlane::CommercialPlane(const CommercialPlane& other)
    : Airplane(other),
    numOfSeats(other.numOfSeats), actualSeatsOccupied(other.actualSeatsOccupied), totalBaggageWeight(other.totalBaggageWeight) {}

CommercialPlane::~CommercialPlane() {}

CommercialPlane& CommercialPlane::operator=(const CommercialPlane& other) {
    if (this == &other) return *this; // Self-assignment check

    Airplane::operator=(other); // Assign base class parts
    numOfSeats = other.numOfSeats;
    actualSeatsOccupied = other.actualSeatsOccupied;
    totalBaggageWeight = other.totalBaggageWeight;

    return *this;
}

int CommercialPlane::getNumOfSeats() const {
    return numOfSeats;
}

void CommercialPlane::setNumOfSeats(int numOfSeats) {
    this->numOfSeats = numOfSeats;
}

int CommercialPlane::getActualSeatsOccupied() const {
    return actualSeatsOccupied;
}

void CommercialPlane::setActualSeatsOccupied(int actualSeatsOccupied) {
    this->actualSeatsOccupied = actualSeatsOccupied;
}

int CommercialPlane::getTotalBaggageWeight() const {
    return totalBaggageWeight;
}

void CommercialPlane::setTotalBaggageWeight(int totalBaggageWeight) {
    this->totalBaggageWeight = totalBaggageWeight;
}

void CommercialPlane::occupyASeat() {
    if (actualSeatsOccupied < numOfSeats) {
        actualSeatsOccupied++;
        const int averagePersonWeight = 70; // Assume average person weight is 70 kg
        setCurrentWeight(getCurrentWeight() + averagePersonWeight);
    }
    else {
        std::cerr << "All seats are occupied." << std::endl;
    }
}

void CommercialPlane::addBaggage(int baggageWeight) {
    totalBaggageWeight += baggageWeight;
    setCurrentWeight(getCurrentWeight() + baggageWeight);
}

void CommercialPlane::display() const {
    Airplane::display();
    std::cout << "Number of Seats: " << numOfSeats << std::endl;
    std::cout << "Actual Seats Occupied: " << actualSeatsOccupied << std::endl;
    std::cout << "Total Baggage Weight: " << totalBaggageWeight << " kg" << std::endl;
}

#endif