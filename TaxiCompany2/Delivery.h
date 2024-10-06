#ifndef DELIVERY_H
#define DELIVERY_H

#define MAX_WEIGHT 40.0

#include "Ride.h"
#include "TripReservation.h"

class Delivery : public virtual Ride, public TripReservation {

private:
    char* product;
    double weight;

public:
    // Constructors
    Delivery(int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay, Customer& cust, Driver& drv, const Date& date, const char* product, double weight);
	Delivery(TripReservation& trip/* =TripReservation()*/, const char* product /*= ""*/, double weight );
    Delivery(const Delivery& other);        // Copy Constructor
    Delivery(Delivery&& other)noexcept;     // Move Constructor
    ~Delivery();                            // Destructor

    Delivery& operator=(const Delivery& other);
    Delivery& operator=(Delivery&& other) noexcept;
    // Getters
    const char* getProduct() const;
    const double getWeight() const;

    // Setters
    bool setProduct(const char* product);
    bool setWeight(double weight);


};

#endif // DELIVERY_H
