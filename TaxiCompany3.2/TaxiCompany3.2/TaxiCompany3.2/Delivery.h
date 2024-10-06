#ifndef DELIVERY_H
#define DELIVERY_H

#include "Ride.h"
#include "TripReservation.h"
#include "Date.h"

class Delivery : virtual public Ride, public TripReservation {
    std::string product;
    double weight;

public:
    Delivery(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay,
        Customer& cust, Driver& drv, const Date& date, const std::string& product, double weight);

    Delivery(TripReservation& trip, const std::string& product, double weight);

    friend std::ostream& operator<<(std::ostream& os, const Delivery& delivery);

    const std::string& getProduct() const;
    double getWeight() const;

    bool setProduct(const std::string& product);
    bool setWeight(double weight);
};

#endif // DELIVERY_H
