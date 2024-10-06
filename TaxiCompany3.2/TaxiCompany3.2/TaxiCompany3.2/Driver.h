#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include "Taxi.h"
#include <string>
#include "LinkedList.h"
 
class Ride;
class TaxiCompany;
class Driver : public Person {
    friend class TaxiCompany;
private:
	const std::string licenseNumber;
    int  rideCount;
    LinkedList<Ride> rideList;
    Taxi& taxi;

public:
    // Constructors
    Driver(Taxi& taxi, const std::string& name, const std::string& id,
            const std::string& licenseNumber, LinkedList<Ride> rideList = {});

    const Driver& operator=(const Driver& other);
    bool operator==(const Driver& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Driver& driver);

    // Getters
    const std::string& getLicenseNumber() const;
    const int getRideCount() const;
    const LinkedList<Ride>& getRideList() const;
    const Taxi& getTaxi() const;

    // Setters
    bool setName(const std::string& name) override;
    bool setId(const std::string& id);
    bool setRideCount(int rideCount);
    bool setRideList(LinkedList<Ride> rideL, int size);
    bool setTaxi(const Taxi& taxi);

    double getRidePrice(Ride* pRide);
};

#endif // DRIVER_H
