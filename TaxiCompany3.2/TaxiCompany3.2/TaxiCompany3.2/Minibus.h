#ifndef MINIBUS_H
#define MINIBUS_H

#include "Taxi.h"
#include <string>


class Minibus : public Taxi {
public:
    Minibus(const std::string& vehicleNumber, const std::string& color);

    std::string getType() const override;
};

#endif // MINIBUS_H
