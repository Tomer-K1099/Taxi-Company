#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include "Taxi.h"
#include "PrivateTaxi.h"

class Ride;

const int LICENSE_NUMBER_SIZE = 7;

class Driver : public Person {

private:
    char licenseNumber[LICENSE_NUMBER_SIZE + 1];
    int  rideCount;
    Ride** rideArr;
    Taxi& taxi;

public:
    // Constructors
    Driver(Taxi& taxi, const char* name, const char* id, const char* licenseNumber, int rideCount = 0, Ride** rideArr = nullptr);
    Driver(const Driver& other);        // Copy Constructor
    Driver(Driver&& other);             // Move Constructor
    ~Driver();                            // Destructor

   const Driver& operator=(const Driver& other);
   const Driver& operator=(Driver&& other);

    bool operator==(const Driver& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Driver& driver);

    // Getters
    const char* getLicenseNumber() const;
    const int         getRideCount() const;
    const Ride*const* getRide() const;
    const Taxi& getTaxi() const;

    // Setters
    bool setName(const char* name);
    bool setId(const char* id);
    bool setLicenseNumber(const char* licenseNumber);
    bool setRideCount(int rideCount);
    bool setRide(Ride** ride,int size);
    bool setTaxi(const Taxi& taxi);
    Ride& addRide(Ride& ride);
    double  getRidePrice(Ride* pRide);//finds the price of a ride within the driver's ride array

};

#endif // DRIVER_H

