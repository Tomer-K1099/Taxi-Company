#ifndef _MAIN_CPP
#define _MAIN_CPP
// main.cpp
#include "Employee.h"
#include "Passenger.h"
#include "Airplane.h"
#include "CargoPlane.h"
#include <iostream>

int main() {
    // Creating an Employee object
    Employee employee("John Doe", 30, "Male", "123 Main St", "555-1234", 101, "Manager", 75000);

    // Displaying the employee's information
    employee.display();

    // Modifying the employee's information
    employee.setName("Jane Doe");
    employee.setAge(28);
    employee.setGender("Female");
    employee.setAddress("456 Elm St");
    employee.setPhoneNumber("555-5678");
    employee.setEmployeeID(102);
    employee.setPosition("Senior Manager");
    employee.setSalary(85000);

    // Displaying the modified employee's information
    employee.display();

    // Creating a Passenger object
    Passenger passenger("Alice Smith", 25, "Female", "789 Pine St", "555-6789", 201, "A12345", "UA123");

    // Displaying the passenger's information
    passenger.display();

    // Modifying the passenger's information
    passenger.setName("Bob Brown");
    passenger.setAge(30);
    passenger.setGender("Male");
    passenger.setAddress("321 Oak St");
    passenger.setPhoneNumber("555-9876");
    passenger.setPassengerID(202);
    passenger.setTicketNumber("B67890");
    passenger.setFlightNumber("DL456");

    // Displaying the modified passenger's information
    passenger.display();

    // Creating an Airplane object
    Airplane airplane(20000, 15000, 5000, "Boeing 747", Airplane::Parked);

    // Displaying the airplane's information
    airplane.display();

    // Modifying the airplane's information
    airplane.setWeightCapacity(25000);
    airplane.setCurrentWeight(18000);
    airplane.setFuelAmount(7000);
    airplane.setModel("Airbus A380");
    airplane.setState(Airplane::Takeoff);

    // Displaying the modified airplane's information
    airplane.display();

    // Creating a CargoPlane object
    CargoPlane cargoPlane(30000, 20000, 8000, "Boeing 747F", Airplane::Parked, true, CargoPlane::Hazardous);

    // Displaying the cargo plane's information
    cargoPlane.display();

    // Modifying the cargo plane's information
    cargoPlane.setWeightCapacity(35000);
    cargoPlane.setCurrentWeight(22000);
    cargoPlane.setFuelAmount(9000);
    cargoPlane.setModel("Airbus A330F");
    cargoPlane.setState(Airplane::Taxi);
    cargoPlane.setTemperatureControlled(false);
    cargoPlane.setCargoType(CargoPlane::Oversized);

    // Displaying the modified cargo plane's information
    cargoPlane.display();

    // Adding cargo interactively
    try {
        cargoPlane.addCargo();
    }
    catch (const std::exception& e) {
        std::cerr << "Error adding cargo: " << e.what() << std::endl;
    }

    // Adding cargo non-interactively
    try {
        cargoPlane.addCargo(CargoPlane::NonPerishable, 5000);
    }
    catch (const std::exception& e) {
        std::cerr << "Error adding cargo: " << e.what() << std::endl;
    }

    return 0;
}

#endif // !_MAIN_CPP
