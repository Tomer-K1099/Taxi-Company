#ifndef MINIBUS_H
#define MINIBUS_H

#include "Taxi.h"



class Minibus : public Taxi {

public:

    // Constructors
	Minibus(const char* vehicleNumber, const char* color);  //sets Taxi.maxPassengers to 15
    // Setters
    /*bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);*/
    // Override the getType function
    const char* getType() const override;
    //const Taxi* findTaxiByTaxiNumber(char* vehicleNumber, const Taxi** taxiArr, int count) const override;
};

#endif // MINIBUS_H

