#ifndef RIDE_H
#define RIDE_H

#include "Address.h"
#include "Payment.h"
#include "Customer.h"
#include "Driver.h"

class Ride {
protected:
    int rideID;
    int numberOfPassengers;
    int rideTime;
    Address originAddress;
    Address destAddress;
    Payment payment;
    Customer& customer;
    Driver& driver;

public:
    Ride(Driver& drv, Customer& cust, int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay);

    Ride(const Ride& other);
	Ride(Ride&& other) noexcept;

    Ride& operator=(const Ride& other);
    Ride& operator=(Ride&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Ride& ride);

    int getRideID() const;
    int getNumberOfPassengers() const;
    int getRideTime() const;
    const  Address& getOriginAddress() const;
    const Address& getDestAddress() const;
    const Payment& getPayment() const;
    const Customer& getCustomer() const;
    const Driver& getDriver() const;

    bool setRideID(int id);
    bool setNumberOfPassengers(int passengers);
    bool setRideTime(int time);
    bool setOriginAddress(const Address& origin);
    bool setDestAddress(const Address& dest);
    bool setPayment(const Payment& pay);

    double getRidePrice();
};

#endif // RIDE_H
