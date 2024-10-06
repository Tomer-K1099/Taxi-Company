#include "TripReservation.h"
#include <utility>

// Constructor
TripReservation::TripReservation(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay,
    Customer& cust, Driver& drv, const Date& date)
    : Ride(drv, cust, id, passengers, time, origin, dest, pay), reservationDate(date) {}

TripReservation::TripReservation(const Ride& ride, const Date& date)
	: Ride(ride),reservationDate(date)
{}

//// Move Constructor
//TripReservation::TripReservation(TripReservation&& other) noexcept
//    : Ride(std::move(other)), reservationDate(std::move(other.reservationDate)) {}
//
//// Move Assignment Operator
//TripReservation& TripReservation::operator=(TripReservation&& other) noexcept {
//    if (this != &other) {
//        //Ride::operator=(std::move(other));
//        reservationDate = std::move(other.reservationDate);
//    }
//    return *this;
//}
//TripReservation::TripReservation(const TripReservation& other)
//    : Ride(other),  // Call the copy constructor of the base class Ride
//    reservationDate(other.reservationDate) {
//}
//TripReservation& TripReservation::operator=(const TripReservation& other) {
//    if (this != &other) {
//        // First, call the base class assignment operator
//        Ride::operator=(other);
//
//        // Then copy the reservationDate member
//        reservationDate = other.reservationDate;
//    }
//    return *this;
//}
std::ostream& operator<<(std::ostream& os, const TripReservation& tripReservation) {
    os << " ########## Reservation Date: " << tripReservation.getReservationDate();
	os << static_cast<const Ride&>(tripReservation);  // Call the base class operator<<
    return os;
}

// Getters
const Date& TripReservation::getReservationDate() const {
    return reservationDate;
}

// Setters
bool TripReservation::setReservationDate(const Date& date) {
    reservationDate = date;
    return true;
}
