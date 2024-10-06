#ifndef TAXI_H
#define TAXI_H
#include <iostream>

const int VEHICLE_NUMBER_SIZE = 8;

class Taxi {// abstract 

protected:
    char vehicleNumber[VEHICLE_NUMBER_SIZE + 1];
    char* color;
    const int maxPassengers;

public:

    // Constructors
    Taxi(const char* vehicleNumber, const char* color, const int maxPassengers);
    Taxi(const Taxi& other);        // Copy Constructor
    Taxi(Taxi&& other);            // Move Constructor
    virtual ~Taxi();               // Destructor

    Taxi& operator=(const Taxi& other);
    Taxi& operator=(Taxi&& other) noexcept;

	bool operator==(const Taxi& other) const;

    // Getters
    const char* getVehicleNumber() const;
    const char* getColor() const;
    const int getMaxPassengers() const;
    virtual const char*  getType() const = 0;

    // Setters
    bool setVehicleNumber(const char* vehicleNumber);
    bool setColor(const char* color);

    // Overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Taxi& taxi);

    const  Taxi* findTaxiByTaxiNumber(char* vehicleNumber, const Taxi** taxiArr, int count) const;
};

#endif // TAXI_H

