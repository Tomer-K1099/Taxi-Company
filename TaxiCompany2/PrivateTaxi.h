#ifndef PRIVATE_TAXI_H
#define PRIVATE_TAXI_H
#include "Taxi.h"

class PrivateTaxi : public Taxi {

public:

    // Constructors
    PrivateTaxi(const char* vehicleNumber , const char* color); //sets Taxi.maxPassengers to 5

    //// Getters
    // Override the getType function
    const char* getType() const override;
 
};

#endif // PRIVATE_TAXI_H
