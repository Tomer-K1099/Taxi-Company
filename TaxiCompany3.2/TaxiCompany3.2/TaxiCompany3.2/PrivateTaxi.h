#ifndef PRIVATE_TAXI_H
#define PRIVATE_TAXI_H
#include "Taxi.h"
#include <string>  

//Concrete Product class for creating Taxi objects (Factory Method design pattern)


class PrivateTaxi : public Taxi {

public:

    // Constructors
    PrivateTaxi(const std::string&  vehicleNumber , const std::string&  color); //sets Taxi.maxPassengers to 5

    //// Getters


    // Setters
    // Override the getType function
    std::string getType() const override;

};

#endif // PRIVATE_TAXI_H
