#ifndef AIRPORT_H
#define AIRPORT_H
#define IATA_CODE_LEN 3

#include "Passenger.h"
#include "Employee.h"
#include "Company.h"
#include "Runway.h"
#include "Airplane.h"
#include "Airline.h"

class Airport {
private:
    char* name;
    const char code[IATA_CODE_LEN]; //Every airport has its unique IATA code. i.e  TLV: Ben Gurion International Airport , LAX: Los Angeles International Airport
    Employee** employees;
    Airplane** planes;
    Company** companies;
    Runway* const runways; //can't change object's address , can change runway contents.

public:
    // Constructors
    Airport(const char* name, char* code, const Employee* employees,const  Airplane** planes, const Company* companies, const Runway* runways);
    ~Airport();
    Airport(const Airport& other); 
    Airport(Airport&& other); 

    //Operators
    Airport& operator=(const Airport& other);    //assignment operator
    Airport& operator=(Airport&& other);    // Move assignment operator


    // Getters and Setters
    char* getName() const;
    void setName(char* name);

    Employee* getEmployees() const;
    void setEmployees(Employee** employees);

    Airplane** getAirplanes() const;
    void setAirplanes(Airplane** airplanes);

    Company* getCompanies() const;
    void setCompanies(Company** companies);

    Runway* getRunways() const;
    void setRunways(Runway* runways);

    //Main Functions
    bool LandAircraft();
    bool DepartAircraft();
    void assignRunway(Airplane& airplane, Runway* runway);   /* helper functions            */ 
    bool addAirplane(Airplane& plane);                       /* to be used by the           */
    bool removeAirplane(int serialNum);                      /* Land/Depart functions.      */
    
    bool checkValidIATA(const char* code); //should be 3 capital letters

    bool addEmployee();
    bool addEmployee(Employee* freshMeat);
    bool removeEmployee();
    bool removeEmployee(const int ID);

    bool addAirline();
    bool addAirline(Airline* airline);

    void printAllAirlines() const;
    void printAllPlanes() const; //only those which are in the airport
    void printAllEmployees() const;




};

#endif // AIRPORT_H
