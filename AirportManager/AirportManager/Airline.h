#ifndef _AIRLINE_H  
#define _AIRLINE_H

#include "Company.h"   
#include "Airplane.h"  
#include "Person.h"   
#include "Passenger.h"
class Airline : public Company  
{
private:
    Airplane* airplanesArr; 
    Passenger** Passengers;

public:
    //Constructors
    Airline(const char* name, const int businessNumber, Airplane* airplanesArr, Employee* employees, const int count = 0, const int capacity = 20);
    Airline(const Airline& other);

    ~Airline();

    Airline(Airline&& other);

    //Operators Overloading
    Airline& operator=(Airline&& other);/*Assignment operator*/
    friend std::ostream& operator<<(std::ostream& os, const Airline& airline); /*Print operator*/

    //Setters Getters
    Airplane* getAirplanesArr() const;
    void setAirplanesArr(const Airplane* airplanes);

    Employee* getPassengers() const;
    void setPassengers(const Passenger** passengers);
   
    void addPassenger(const Passenger& passenger);
    void removePassenger(int passengerID);

    void addPlane(const Airplane& plane);
    void removePlane(const int serialNum);
};

#endif // _AIRLINE_H
