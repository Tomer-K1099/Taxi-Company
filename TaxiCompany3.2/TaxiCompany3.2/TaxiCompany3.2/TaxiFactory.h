#ifndef TAXIFACTORY_H
#define TAXIFACTORY_H

#include "Taxi.h"

//Abstract Creator class  (Factory Method design pattern)

class TaxiFactory {
public:
    virtual ~TaxiFactory() {}
    virtual Taxi* createTaxi(const std::string& vehicleNumber, const std::string& color) const = 0;
};

#endif // TAXIFACTORY_H
