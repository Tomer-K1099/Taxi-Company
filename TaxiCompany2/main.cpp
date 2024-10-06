#include <iostream>
#include <string>
#include "Address.h"
#include "Customer.h"
#include "Driver.h"
#include "Minibus.h"
#include "PrivateTaxi.h"
#include "Payment.h"
#include "Ride.h"
#include "Delivery.h"
#include "Date.h"
#include "TripReservation.h"
#include "TaxiCompany.h"


enum eMenuOptions
{
    eAddDriver, eAddTaxi, eAddCustomer, eAddTripReservation, eAddRide, eAddDelivery, ePrintCompany, ePrintDrivers, ePrintTaxis, ePrintCustomers, ePrintRides,
    ePrintDeliveries, ePrintTripReservation, eCalculateIncome, eCalculateOutcome, eNofOptions
};

const std::string str[eNofOptions] = { "Add Driver","Add Taxi", "Add Customer", "Add Trip Reservation", "Add ride", "Add delivery"
                                     , "Print Taxi Company", "Print all Drivers", "Print all Taxis", "Print all Customers", "Print all Rides",
                                      "Print all deliveries", "Print all Trip Reservations", "Calculate income",
                                      "Calculate outcome"};

#define EXIT -1


int menu();

int main()
{

    // Creating Address instances
    Address address1(123, "Main St", "Tel Aviv");
    Address address2(456, "Second St", "Jerusalem");
    Address address3(789, "Third St", "Haifa");

    // Creating Customer instances
    Customer customer1("Alice", "123456789", "0501234567");
    Customer customer2("Bob", "987654321", "0507654321");

    // Creating Taxi instances
    PrivateTaxi privateTaxi1("1234ABC", "Yellow");
    Minibus minibus1("5678DEF", "Blue");

    // Creating Payment instances
    Payment payment1(Credit, 100);
    Payment payment2(Cash, 200);

    // Creating Driver instances
    Driver driver1(privateTaxi1, "Charlie", "111222333", "A123456", 0, nullptr);
    Driver driver2(minibus1, "David", "444555666", "B654321", 0, nullptr);

    // Creating Ride instances
    Ride ride1(driver1, customer1, 1, 3, 30, address1, address2, payment1);
    Ride ride2(driver2, customer2, 2, 2, 45, address2, address3, payment2);

    // Creating Date instances
    Date date1(1, 1, 2024);
    Date date2(2, 2, 2024);

    // Creating TripReservation instances
    TripReservation tripReservation1(1, 3, 30, address1, address2, payment1, customer1, driver1, date1);
    TripReservation tripReservation2(2, 2, 45, address2, address3, payment2, customer2, driver2, date2);
	
    // Creating Delivery instances
    Delivery delivery1(1, 3, 30, address1, address2, payment1, customer1, driver1, date1, "Laptop", 5.0);
    Delivery delivery2(2, 2, 45, address2, address3, payment2, customer2, driver2, date2, "Furniture", 20.0);

	TaxiCompany* myCompany; // Creating TaxiCompany instance
    try{  
        myCompany= new TaxiCompany("My Taxi Company", address1);
    }
    catch (const char* msg) {
        std::cout << msg;
        return 1;
}

    // Adding Taxis to the company
    myCompany->addTaxi(privateTaxi1);
    myCompany->addTaxi(minibus1);

    // Adding Drivers to the company
    myCompany->addDriver(driver1);
    myCompany->addDriver(driver2);

    // Adding Customers to the company
    myCompany->addCustomer(customer1);
    myCompany->addCustomer(customer2);

    // Adding Rides to the company
    myCompany->addRide(ride1, driver1);
    myCompany->addRide(ride2, driver2);

    // Adding Trip Reservations to the company
    myCompany->addTripReservation(tripReservation1);
    myCompany->addTripReservation(tripReservation2);

    // Adding Deliveries to the company
    myCompany->addDelivery(delivery1);
    myCompany->addDelivery(delivery2);

    int option;
    bool stop = false;

    do
    {
        option = menu();
        switch (option)
        {
        case eAddDriver:
            myCompany->addDriver();
            break;

        case eAddTaxi:
            myCompany->addTaxi();
            break;

        case eAddCustomer:
            myCompany->addCustomer();
            break;

        case eAddTripReservation:
            myCompany->addTripReservation();
            
        
        case eAddRide:
            myCompany->addRide();
            break;

        case eAddDelivery:
            myCompany->addDelivery();
            break;

        case ePrintCompany:
			myCompany->printTaxiCompany(*myCompany);
            break;
        case ePrintDrivers:
			myCompany->printDrivers();
			break;

		case ePrintTaxis:
			myCompany->printTaxis();
			break;

		case ePrintCustomers:
			myCompany->printCustomers();
			break;

        case ePrintRides:
            myCompany->printRides();
            break;

        case ePrintDeliveries:
            myCompany->printDeliveries();
            break;

        case ePrintTripReservation:
            myCompany->printTripReservations();
            break;

        case eCalculateIncome:
            myCompany->calculateIncome();
            break;

        case eCalculateOutcome:
            myCompany->calculateOutcome();
            break;

        case EXIT:
            std::cout << "Bye bye" << std::endl;
            stop = true;
            break;

        default:
            std::cout << "Wrong option" << std::endl;
            break;
        }
    } while (!stop);

	delete myCompany;
    return 0;
}

int menu()
{
    int option;
    std::cout << "\n\n";
    std::cout << "Please choose one of the following options" << std::endl;
    for (int i = 0; i < eNofOptions; i++)
        std::cout << i << " - " << str[i] << std::endl;
    std::cout << EXIT << " - Quit" << std::endl;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean buffer
    return option;
}
