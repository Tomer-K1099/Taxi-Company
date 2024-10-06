#ifndef TAXI_H
#define TAXI_H
#include <iostream>
#include <string>  


const int VEHICLE_NUMBER_SIZE = 8;

class Taxi {// abstract 

protected:
    const std::string vehicleNumber;
    std::string color;
    const int maxPassengers;

public:
    //Abstract Product class  (Factory Method design pattern)
    // Constructors 
    Taxi(const std::string&  vehicleNumber, const std::string&  color, const int maxPassengers);


    Taxi& operator=(const Taxi& other);
    Taxi& operator=(Taxi&& other) noexcept;

	bool operator==(const Taxi& other) const;

    // Getters
    const std::string&  getVehicleNumber() const;
    const std::string&  getColor() const;
    const int getMaxPassengers() const;
    virtual std::string getType() const = 0; 

    // Setters
    bool setColor(const std::string&  color);

    // Overload << operator
    friend std::ostream& operator<<(std::ostream& os, const Taxi& taxi);

    const  Taxi* findTaxiByTaxiNumber(std::string&  vehicleNumber, const Taxi** taxiArr, int count) const;
};

#endif // TAXI_H

