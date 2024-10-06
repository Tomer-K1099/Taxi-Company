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
    // Constructors
   
    Ride(Driver& drv , Customer& cust, int id, int passengers, int time, const Address& origin, const Address& dest, const Payment& pay) ;
    Ride(Ride&& other) noexcept; // Move Constructor
    Ride(const Ride& other);  // Copy constructor
    ~Ride();  // Declare the destructor here

    // Assignment Operators
    Ride& operator=(const Ride& other);
    Ride& operator=(Ride&& other);

    friend std::ostream& operator<<(std::ostream& os, const Ride& ride);

    // Getters
    const int getRideID() const;
    const int getNumberOfPassengers() const;
    const int getRideTime() const;
    const Address& getOriginAddress() const;
    const Address& getDestAddress() const;
    const Payment& getPayment() const;
    const Customer& getCustomer() const;
    const Driver& getDriver() const;

    // Setters
    bool setRideID(int id);
    bool setNumberOfPassengers(int passengers);
    bool setRideTime(int time);
    bool setOriginAddress(const Address& origin);
    bool setDestAddress(const Address& dest);
    bool setPayment(const Payment& pay);


    double getRidePrice();
    
};

#endif // RIDE_H
