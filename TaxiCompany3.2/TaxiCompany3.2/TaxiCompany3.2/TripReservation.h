#ifndef TRIPRESERVATION_H
#define TRIPRESERVATION_H

#include "Address.h"
#include "Payment.h"
#include "Customer.h"
#include "Driver.h"
#include "Date.h"
#include "Ride.h"

class TripReservation : public virtual Ride {
protected:
    Date reservationDate;

public:
    TripReservation(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay,
                    Customer& cust, Driver& drv, const Date& date);
	TripReservation(const Ride& ride, const Date& date); 
    
    friend std::ostream& operator<<(std::ostream& os, const TripReservation& tripReservation);

    const Date& getReservationDate() const;
     
    bool setReservationDate(const Date& date);
};

#endif // TRIPRESERVATION_H
