#include "Delivery.h"
#include <utility>

// Constructor
Delivery::Delivery(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay,
    Customer& cust, Driver& drv, const Date& date, const std::string& product, double weight)
    : Ride(drv, cust, id, passengers, time, origin, dest, pay),
    TripReservation(id, passengers, time, origin, dest, pay, cust, drv, date),
    product(product), weight(weight) {
    // Additional initialization if needed
}

// Constructor from TripReservation
Delivery::Delivery(TripReservation& trip, const std::string& product, double weight)
    : Ride(trip), TripReservation(trip) , product(product), weight(weight) {
}


std::ostream& operator<<(std::ostream& os, const Delivery& delivery) {
    os << " ########## Product: " << delivery.getProduct()
       << " ########## Weight: " << delivery.getWeight();
    os << static_cast<const TripReservation&>(delivery); // Output the Ride part
    return os;
}

// Getters
const std::string& Delivery::getProduct() const {
    return product;
}

double Delivery::getWeight() const {
    return weight;
}

// Setters
bool Delivery::setProduct(const std::string& product) {
    this->product = product;
    return true;
}

bool Delivery::setWeight(double weight) {
    this->weight = weight;
    return true;
}

