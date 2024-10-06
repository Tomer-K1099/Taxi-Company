#ifndef TRIPRESERVATION_H
#define TRIPRESERVATION_H
#include <iostream>
#include "Ride.h"
#include "Date.h"

class TripReservation : public virtual Ride {

protected:
    Date date;

public:
    // Constructors
    TripReservation(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay, Customer& cust, Driver& drv, const Date& date);
    TripReservation(Ride& ride, const Date& date);

    friend std::ostream& operator<<(std::ostream& os, const TripReservation& trip);
	// == operator
	bool operator==(const TripReservation& other) const;
    // Getters
    const Date& getDate() const;

    // Setters
    bool setDate(const Date& date);

    int getRidePrice(Ride& ride);

};

#endif // TRIPRESERVATION_H

