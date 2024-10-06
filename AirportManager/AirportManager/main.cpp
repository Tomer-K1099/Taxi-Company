#ifndef _MAIN_CPP
#define _MAIN_CPP
//// main.cpp
#include "Airport.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define EXIT - 1

typedef enum
{
	ePrintAirlines,ePrintEmployees,ePrintPlanes,ePrintAirport,eLandPlane,eDepartPlane, eAddAirline,eAddEmployee, eRemoveEmployee, eNofOptionsMenu
} eMenuOptions;

const char* menu_str[eNofOptionsMenu] = { "Print all airlines" , "Print all employees", 
										  "Print all planes that are at the airport", 
										  "Land a plane" , "Depart a plane", "Add an airline",
										  "Add an employee" , "Fire an employee", "Exit" };


int menu();

int main()
{
	char name[MAX_AP_NAME_LEN];
	char code[IATA_CODE_LEN];
	int num_runways;
	int option , stop=0;
	std::cout << "Airport name?";
	std::cin >> name;
	std::cout << "IATA code? (3 capital letters):  ";
	std::cin >> code;
	std::cout << "How many runways your aiport has? ";
	std::cin >> num_runways;

	Runway* const runways = new Runway[num_runways];
	Employee** employeeArr = nullptr;
	Airplane** planeArr = nullptr;
	Company** companyArr = nullptr;

	Airport airport = Airport(name, code, employeeArr, planeArr, companyArr, runways);

	do
	{
		option = menu();
		switch (option)
		{
		case ePrintAirlines:
			airport.printAllAirlines();
			break;

		case ePrintEmployees:
			airport.printAllEmployees();
			break;

		case ePrintPlanes:
			airport.printAllPlanes();
			break;

		case ePrintAirport:
			airport.display();
			break;

		case eLandPlane:
			airport.LandAircraft();
			break;

		case eDepartPlane:
			airport.DepartAircraft();
			break;

		case eAddAirline:
			airport.addAirline();
			break;

		case eAddEmployee:
			airport.addEmployee();
			break;

		case eRemoveEmployee:
			airport.removeEmployee();
			break;

		case EXIT:
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);

	
	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for (int i = 0; i < eNofOptionsMenu; i++)
		printf("%d - %s\n", i, menu_str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}
#endif
//
//int main() {
//    // Creating an Employee object
//    Employee employee("John Doe", 30, "Male", "123 Main St", "555-1234", 101, "Manager", 75000);
//
//    // Displaying the employee's information
//    employee.display();
//
//    // Modifying the employee's information
//    employee.setName("Jane Doe");
//    employee.setAge(28);
//    employee.setGender("Female");
//    employee.setAddress("456 Elm St");
//    employee.setPhoneNumber("555-5678");
//    employee.setEmployeeID(102);
//    employee.setPosition("Senior Manager");
//    employee.setSalary(85000);
//
//    // Displaying the modified employee's information
//    employee.display();
//
//    // Creating a Passenger object
//    Passenger passenger("Alice Smith", 25, "Female", "789 Pine St", "555-6789", 201, "A12345", "UA123");
//
//    // Displaying the passenger's information
//    passenger.display();
//
//    // Modifying the passenger's information
//    passenger.setName("Bob Brown");
//    passenger.setAge(30);
//    passenger.setGender("Male");
//    passenger.setAddress("321 Oak St");
//    passenger.setPhoneNumber("555-9876");
//    passenger.setPassengerID(202);
//    passenger.setTicketNumber("B67890");
//    passenger.setFlightNumber("DL456");
//
//    // Displaying the modified passenger's information
//    passenger.display();
//
//    // Creating an Airplane object
//    Airplane airplane(20000, 15000, 5000, "Boeing 747", Airplane::Parked);
//
//    // Displaying the airplane's information
//    airplane.display();
//
//    // Modifying the airplane's information
//    airplane.setWeightCapacity(25000);
//    airplane.setCurrentWeight(18000);
//    airplane.setFuelAmount(7000);
//    airplane.setModel("Airbus A380");
//    airplane.setState(Airplane::Takeoff);
//
//    // Displaying the modified airplane's information
//    airplane.display();
//
//    // Creating a CargoPlane object
//    CargoPlane cargoPlane(30000, 20000, 8000, "Boeing 747F", Airplane::Parked, true, CargoPlane::Hazardous);
//
//    // Displaying the cargo plane's information
//    cargoPlane.display();
//
//    // Modifying the cargo plane's information
//    cargoPlane.setWeightCapacity(35000);
//    cargoPlane.setCurrentWeight(22000);
//    cargoPlane.setFuelAmount(9000);
//    cargoPlane.setModel("Airbus A330F");
//    cargoPlane.setState(Airplane::Taxi);
//    cargoPlane.setTemperatureControlled(false);
//    cargoPlane.setCargoType(CargoPlane::Oversized);
//
//    // Displaying the modified cargo plane's information
//    cargoPlane.display();
//
//    // Adding cargo interactively
//    try {
//        cargoPlane.addCargo();
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error adding cargo: " << e.what() << std::endl;
//    }
//
//    // Adding cargo non-interactively
//    try {
//        cargoPlane.addCargo(CargoPlane::NonPerishable, 5000);
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error adding cargo: " << e.what() << std::endl;
//    }
//
//    return 0;
//}
//
//#endif // !_MAIN_CPP
