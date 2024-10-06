// MinibusFactory.h
#ifndef MINIBUSFACTORY_H
#define MINIBUSFACTORY_H

#include "TaxiFactory.h"
#include "Minibus.h"

//Concrete Creator class for creating Taxi objects (Factory Method design pattern)

class MinibusFactory : public TaxiFactory {
public:
    Taxi* createTaxi(const std::string& vehicleNumber, const std::string& color) const override {
        return new Minibus(vehicleNumber, color);
    }
};

#endif // MINIBUSFACTORY_H
