#include "Delivery.h"
#include <iostream>
#include <cstring>  // for strlen and strcpy

// Constructor
Delivery::Delivery(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay,
    Customer& cust, Driver& drv, const Date& date, const char* product, double weight)
    : Ride(drv, cust, id, passengers, time, origin, dest, pay),
    TripReservation(id, passengers, time, origin, dest, pay, cust, drv, date),
    weight(weight){
    setProduct(product);
}

Delivery::Delivery(TripReservation& trip, const char* product, double weight) : Ride(trip), TripReservation(trip), weight(weight)  {
	setProduct(product);
}


// Copy Constructor for Delivery
Delivery::Delivery(const Delivery& other)
    : Ride(other), TripReservation(other), weight(other.weight), product(nullptr) {
    setProduct(other.product); // Deep copy of the product string
	
}   

// Move Constructor
Delivery::Delivery(Delivery&& other) noexcept
    : Ride(std::move(other)), TripReservation(std::move(other)), product(std::move(other.product)), weight(other.weight) {
    other.product = nullptr;
}

// Destructor
Delivery::~Delivery() {
    delete[] product;
}

// Copy Assignment Operator
Delivery& Delivery::operator=(const Delivery& other) {
    if (this != &other) {
        Ride::operator=(other);
        TripReservation::operator=(other);

        delete[] product;
        setProduct(other.product);
        weight = other.weight;
    }
    return *this;
}

// Move Assignment Operator
Delivery& Delivery::operator=(Delivery&& other) noexcept {
    if (this != &other) {
        //Ride::operator=(std::move(other));
        //TripReservation::operator=(std::move(other));

        delete[] product;
        product = std::move(other.product);
        other.product = nullptr;
        weight = other.weight;

    }
    return *this;
}

// Getters
const char* Delivery::getProduct() const {
    return product;
}

const double Delivery::getWeight() const {
    return weight;
}

// Setters
bool Delivery::setProduct(const char* product) {
    if (!product) {
        return false;
    }
    this->product = new char[strlen(product) + 1];
    strcpy(this->product, product);
    return true;
}

bool Delivery::setWeight(double weight) {
    if (weight < 0) {
        return false;  // Invalid weight
    }
    this->weight = weight;
    return true;
}

// Method to Calculate Ride Price based on weight

