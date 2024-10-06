#include "TripReservation.h"

// Parameterized Constructor
TripReservation::TripReservation(int id, int passengers, int time, const Address& origin, const Address& dest,
    const Payment& pay, Customer& cust, Driver& drv, const Date& date)
    : Ride(drv, cust, id, passengers, time, origin, dest, pay), date(date) {}

TripReservation::TripReservation(Ride& ride, const Date& date)
    : Ride(ride), date(date) {}

std::ostream& operator<<(std::ostream& os, const TripReservation& trip) {
    // Print the additional TripReservation information
    os << "Date: " << trip.getDate();
    // Print the base Ride class information
    os << Ride(trip);


    return os;
}

bool TripReservation::operator==(const TripReservation& other) const
{
	if (rideID == other.rideID && numberOfPassengers == other.numberOfPassengers && rideTime == other.rideTime &&
		originAddress == other.originAddress && destAddress == other.destAddress && payment == other.payment &&
		customer == other.customer && driver == other.driver && date == other.date)
		return true;
    return false;
}

// Getter for Date
const Date& TripReservation::getDate() const {
    return date;
}

// Setter for Date
bool TripReservation::setDate(const Date& date) {
    this->date = date;
    return true;
}
int TripReservation::getRidePrice(Ride& ride) {
    return ride.getPayment().getPrice(); 
}
