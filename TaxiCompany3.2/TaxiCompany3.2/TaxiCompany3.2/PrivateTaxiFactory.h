#ifndef PRIVATETAXIFACTORY_H
#define PRIVATETAXIFACTORY_H

#include "TaxiFactory.h"
#include "PrivateTaxi.h"

//Concrete Creator class for creating Taxi objects (Factory Method design pattern)

class PrivateTaxiFactory : public TaxiFactory {
public:
    Taxi* createTaxi(const std::string& vehicleNumber, const std::string& color) const override {
        return new PrivateTaxi(vehicleNumber, color);
    }
};

#endif // PRIVATETAXIFACTORY_H