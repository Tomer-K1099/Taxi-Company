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
#include "DriverFacade.h"
#include "CustomerFacade.h"
#include "TaxiFacade.h"
#include "DeliveryFacade.h"
#include "TripReservationFacade.h"
#include "RideFacade.h"

enum eMenuOptions
{
    eDriverManagement=1, eCustomerManagement, eTaxiManagement, eRideManagement,
    eDeliveryManagement, eTripReservationManagement, eCalculateIncome, eCalculateOutcome, eNofOptions
};

const std::string str[eNofOptions-1] = { "Driver", "Customer", "Taxi", "Ride",
	"Delivery", "Trip Reservation", "Calculate Income", "Calculate Outcome" };
#define EXIT -1

int main();

int menu();

int main()
{
    // Creating Address instances
    Address address1(123, "Main St", "Tel Aviv");
    Address address2(456, "Second St", "Jerusalem");
    Address address3(789, "Third St", "Haifa");

	// Creating TaxiCompany instance
	TaxiCompany& myCompany = TaxiCompany::getInstance();
    

    // Creating Customer instances
    Customer customer1("Alice", "123456789", "0501234567");
    Customer customer2("Bob", "987654321", "0507654321");

    // Creating Payment instances
    Payment payment1(Credit, 100);
    Payment payment2(Cash, 200);



 
    // Creating Date instances
    Date date1(1, 1, 2024);
    Date date2(2, 2, 2024);


    // Adding Taxis to the company
    PrivateTaxiFactory privateFactory;
    MinibusFactory minibusFactory;

    myCompany.addTaxi(&privateFactory, "1234ABC", "Yellow");
    myCompany.addTaxi(&minibusFactory, "5678DEF", "Blue");

    
    // Creating Driver instances
    Driver* driver1 = new Driver(*myCompany.getTaxiArr().front(), "Charlie", "111222333", "A123456");
    Driver* driver2 = new Driver(*myCompany.getTaxiArr().back(), "David", "444555666", "B654321");

    // Adding Drivers to the company
    myCompany.addDriver(driver1);
    myCompany.addDriver(driver2);

    // Adding Customers to the company
    myCompany.addCustomer(&customer1);
    myCompany.addCustomer(&customer2);

    // Creating Ride instances
    Ride ride1(*driver1, customer1, 1, 3, 30, address1, address2, payment1);
    Ride ride2(*driver2, customer2, 2, 2, 45, address2, address3, payment2);

    // Adding Rides to the company
    myCompany.addRide(ride1, *driver1);
    myCompany.addRide(ride2, *driver2);

    // Creating TripReservation instances
    TripReservation tripReservation1(1, 3, 30, address1, address2, payment1, customer1, *driver1, date1);
    TripReservation tripReservation2(2, 2, 45, address2, address3, payment2, customer2, *driver2, date2);

    // Creating Delivery instances
    Delivery delivery1(1, 3, 30, address1, address2, payment1, customer1, *driver1, date1, "Laptop", 5.0);
    Delivery delivery2(2, 2, 45, address2, address3, payment2, customer2, *driver2, date2, "Furniture", 20.0);


    // Adding Trip Reservations to the company
    myCompany.addTripReservation(tripReservation1);
    myCompany.addTripReservation(tripReservation2);

    // Adding Deliveries to the company
    myCompany.addDelivery(delivery1);
    myCompany.addDelivery(delivery2);

   
    
	// Initialize the facade classes (Facade design pattern)
    DriverFacade driverFacade;
    CustomerFacade customerFacade;
    TaxiFacade taxiFacade;
	DeliveryFacade deliveryFacade;
	TripReservationFacade tripReservationFacade;
	RideFacade rideFacade;

    int option;
    bool stop = false;

    do
    {
        option = menu();
        switch (option)
        {
        case eDriverManagement:
            driverFacade.displayMenu(myCompany);
            break;
        case eCustomerManagement:
            customerFacade.displayMenu(myCompany);
            break;
        case eTaxiManagement:
			taxiFacade.displayMenu(myCompany);
            break;
        case eRideManagement:
            rideFacade.displayMenu(myCompany);
            break;
        case eDeliveryManagement:
            deliveryFacade.displayMenu(myCompany);
            break;
        case eTripReservationManagement:
            tripReservationFacade.displayMenu(myCompany);
            break;
        case eCalculateIncome:
            myCompany.calculateIncome();
            break;
        case eCalculateOutcome:
            myCompany.calculateOutcome();
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

    return 0;
}

int menu()
{
    int option;
    std::cout << "\n\n";
    std::cout << "Please choose one of the following options" << std::endl;
    for (int i = 1; i < eNofOptions-1; i++)
        std::cout << i << " - " << str[i-1] << std::endl;
    std::cout << EXIT << " - Quit" << std::endl;
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean buffer
    return option;
}
