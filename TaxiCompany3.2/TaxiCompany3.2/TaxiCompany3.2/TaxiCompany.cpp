#include "TaxiCompany.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>


TaxiCompany* TaxiCompany::instance = nullptr;


// Constructor
TaxiCompany::TaxiCompany(const std::string& name, const Address& address,
    const std::list<Driver*>& driversArr,
    const std::list<Taxi*>& taxiArr,
    const std::list<Customer*>& customerArr,
    const std::list<TripReservation>& tripReservationArr,
    const std::list<Delivery>& deliverysArr)
    : name(name), address(address),
    driversList(driversArr), taxiList(taxiArr),
    customerArr(customerArr), tripReservationList(tripReservationArr),
    DeliverysList(deliverysArr) {
    // Additional initialization if needed
}


// Destructor
TaxiCompany::~TaxiCompany() {

    for (Driver* driver : driversList) {
        delete driver;
    }
    for (Taxi* taxi : taxiList) {
        delete taxi;
    }
    for (Customer* customer : customerArr) {
        delete customer;
    }
}

// Singleton instance
TaxiCompany& TaxiCompany::getInstance()
{
	if (!instance) {
		instance = new TaxiCompany("My Taxi Company", Address(123, "Main St", "Tel Aviv"));
	}
    return *instance;
}

// Add a new Taxi interactively
int TaxiCompany::addTaxi() throw (std::string){
    std::string vehicleNumber, color;
	bool valid = true;
	//define a regex pattern for vehicle number (Case-sensitive)
	std::regex vehicleNumberRegex(R"([A-Z0-9]{8})");
    do {
        std::cout << "Enter vehicle number: [8 Symbols] #Only Capital Letters or Numbers : ";
        std::cin >> vehicleNumber;
        if (!std::regex_match(vehicleNumber, vehicleNumberRegex))
        {
            std::cout << "Invalid Vehicle Number." << std::endl;
            valid = false;
        }
        else
        {
			valid = true;
        }
	} while (!valid);

    // Define a regex pattern of colors (case-insensitive)
    std::regex colorRegex(R"(\b(red|green|blue|yellow|black|white|orange|purple|brown|pink|gray|grey)\b)", std::regex::icase);
	do {
		std::cout << "Enter color: ";
		std::cin >> color;
		if (!std::regex_match(color, colorRegex)) {
			std::cout << "Invalid color. Please enter a valid color." << std::endl;
			valid = false;
		}
		else {
			valid = true;
		}
	} while (!valid);


    int choice;
    do {
        std::cout << "Choose which Taxi:\n"<< "[1] - Private Taxi \n[2] - Minibus" << std::endl;
		std::cin >> choice;
	} while (choice!=1 && choice!=2);
    TaxiFactory* factory = nullptr;
    do{
        switch (choice)
        {
	    case 1:
		    factory = new PrivateTaxiFactory();
            valid = true;
		    break;
	    case 2: 
            factory = new MinibusFactory();
            valid = true;
            break;
        default:
            valid = false;
            break;
	    }
	} while (!valid);

    addTaxi(factory, vehicleNumber, color); //Adds Taxi to TaxiList

    delete factory;

    std::cout << "Taxi added successfully!" << std::endl;

    return taxiList.size();
}

int TaxiCompany::addTaxi(TaxiFactory* factory, const std::string& vehicleNumber, const std::string& color) {
    Taxi* taxi = factory->createTaxi(vehicleNumber, color);
    taxiList.push_back(taxi);
	return taxiList.size();
}


int TaxiCompany::addDriver() {
    std::string name, id, licenseNumber;
    int rideCount = 0;
    bool valid = true;
    
    do
    {
        std::cout << "Enter driver's name: ";
        std::cin >> name;
        if (!isAlphabetic(name)) {
            std::cerr << "Invalid name. Please enter alphabetic characters only." << std::endl;
            valid = false;
        }
        else valid = true; 
       
    } while (!valid);
    
    do
    {
        std::cout << "Enter driver's ID: ";
        std::cin >> id;
        if (!isNumeric(id)) {
            std::cerr << "Invalid ID. Please enter numeric characters only." << std::endl;
            valid = false;
        }
        else valid = true;
        
    } while (!valid);

    do
    {
        std::cout << "Enter driver's license number: ";
        std::cin >> licenseNumber;
        if (!isNumeric(licenseNumber)) {
            std::cerr << "Invalid license number. Please enter numeric characters only." << std::endl;
            valid = false;
        }
        else valid = true;
    } while (!valid);
  
    if (taxiList.empty()) {
        std::cerr << "No taxis available to assign to this driver!" << std::endl;
        return driversList.size();
    }

    Taxi* assignedTaxi = taxiList.front();  // Assign the first available taxi
    Driver* newDriver = new Driver(*assignedTaxi, name, id, licenseNumber);

    driversList.push_back(newDriver);
    std::cout << "Driver added successfully!" << std::endl;

    return driversList.size();
}

// Add a new Driver provided as a pointer
int TaxiCompany::addDriver(Driver* newDriver) {
    if (newDriver == nullptr) {
        std::cerr << "Invalid Driver pointer!" << std::endl;
        return 0;
    }

    driversList.push_back(newDriver);
    std::cout << "Driver added successfully!" << std::endl;

    return driversList.size();
}

// Add a new Customer interactively
int TaxiCompany::addCustomer() {
    std::string name, id, phoneNumber;

    std::cout << "Enter customer's name: ";
    std::cin >> name;
    std::cout << "Enter customer's ID: ";
    std::cin >> id;
    std::cout << "Enter customer's phone number: ";
    std::cin >> phoneNumber;

    Customer* newCustomer = new Customer(name, id, phoneNumber);
    customerArr.push_back(newCustomer);
    std::cout << "Customer added successfully!" << std::endl;

    return customerArr.size();
}

// Add a new Customer provided as a pointer
int TaxiCompany::addCustomer(Customer* newCustomer) {
    if (newCustomer == nullptr) {
        std::cerr << "Invalid Customer pointer!" << std::endl;
        return customerArr.size();
    }

    customerArr.push_back(newCustomer);
    std::cout << "Customer added successfully!" << std::endl;

    return customerArr.size();
}

PrivateTaxi* TaxiCompany::displayPrivateTaxis() const {
    std::vector<PrivateTaxi*> privateTaxis;
    privateTaxis.clear();
    int index = 0;
    int choice = -1;
    std::cout << "Choose a private taxi for this ride: " << std::endl;

    for (const auto& taxi : taxiList) {
        PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(taxi);
        if (privateTaxi != nullptr) {
            std::cout << "[" << index << "] " << ":" << *privateTaxi << std::endl;
            privateTaxis.push_back(privateTaxi);
            index++;
        }
    }

    if (privateTaxis.empty()) {
        throw "No private taxis available.";
    }
    else {
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice >= privateTaxis.size()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid choice. Please enter a number between 0 and " << privateTaxis.size() - 1 << ": ";
            }
            else {
                break;
            }
        }
    }
    return privateTaxis[choice];
}

Minibus* TaxiCompany::displayMinibuses() const {
    std::vector<Minibus*> minibuses;
    minibuses.clear();
    int index = 0;
    int choice = -1;
    std::cout << "Choose a minibus for this ride: " << std::endl;

    for (const auto& taxi : taxiList) {
        Minibus* minibus = dynamic_cast<Minibus*>(taxi);
        if (minibus != nullptr) {
			std::cout << "[" << index <<"] " << ":" << *minibus << std::endl;
            minibuses.push_back(minibus);
            index++;
        }
    }

    if (minibuses.empty()) {
       throw "No minibuses available.";
    }
    else {
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice >= minibuses.size()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid choice. Please enter a number between 0 and " << minibuses.size() - 1 << ": ";
            }
            else {
                break;
            }
        }
	}
	return minibuses[choice];

}

// Add a new Ride interactively
Ride& TaxiCompany::addRide() throw (std::string&) {
    int rideID, passengers, rideTime;
    Address *origin=nullptr, *dest = nullptr;
    double price;
    Customer* customer;
    Driver* driver=nullptr;
    std::string originAddressStr, destAddressStr;
    bool valid = false;
    std::cout << "Enter Ride ID: ";
    std::cin >> rideID;
    do {
        std::cout << "Enter number of passengers [Max 15]: ";
        std::cin >> passengers;
	} while (passengers < 1 || passengers > 15 );
    std::cout << "Enter ride time: ";
    std::cin >> rideTime;

	//Select the first available driver that can accommodate the number of passengers
    for (Driver* pDriver :  driversList)
    {
        if (pDriver->getTaxi().getMaxPassengers() >= passengers);
		{
			driver = pDriver;
			break;
		}
    }
    if (driver == nullptr) {
        throw "No drivers available for this ride!";
    }

	// Select the first available customer
    customer = customerArr.front();
    
    price = 20 + rideTime * 2.0 + (passengers > 4 ? 3 * passengers : 0);  // 20 base price + 2 per minute. Minibus costs extra 3 per passenger.
    
    int payChoice;
    do {
        std::cout << "Enter the payment method:\n1. Cash\n2. Credit\n";
        std::cin >> payChoice;
    } while (payChoice != 1 && payChoice != 2);
    
    Payment payment(payChoice == 1 ? Cash : Credit, price);  // Use the default constructor; modify as needed for actual payment details
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Get origin address
	valid = true;
    // Get destination address
    do {
        try {
            std::cout << "Enter the origin address (e.g., 123 Main St, Springfield): ";
            std::getline(std::cin, originAddressStr);
            origin = Address::parseAddress(originAddressStr);
            valid = true;

		}
		catch (std::string& e) {
			std::cerr << e << std::endl;
			valid = false;
        }
	} while (!valid);
      do {
        try {
            std::cout << "Enter the destination address (e.g., 456 Elm St, Springfield): ";
            std::getline(std::cin, destAddressStr);
            dest = Address::parseAddress(destAddressStr);
            valid = true;
		}
		catch (std::string& e) {
			std::cerr << e << std::endl;
			valid = false;
        }
	} while (!valid);

    // For simplicity, we'll select the first customer and driver from the lists
    
    if (customerArr.empty() || driversList.empty()) {
        throw "No customers or drivers available!";
    }

    // Create a new Ride object
    Ride* newRide = new Ride(*driver, *customer, rideID, passengers, rideTime, *origin, *dest, payment);

    // Add to driver's ride list and company's trip list
    driver->rideList.add(*newRide);

    return *newRide;
}

// Add a new Ride provided as a reference
Ride& TaxiCompany::addRide(Ride& newRide, Driver& driver) throw(std::string&) {
    // Add the ride to the driver�s ride list and to the company's trip reservation list
    driver.rideList.add(newRide);

    return newRide;
}

// Add a new Trip Reservation interactively
TripReservation& TaxiCompany::addTripReservation() {
	Ride& newRide = addRide();
    string dateStr;
    Date* date = nullptr;
	//collect date from user
    bool valid = true;
    do
    {
        try
        {
            std::cout << "Enter the date of the reservation [DD/MM/YYYY]: ";
            std::getline(std::cin, dateStr);
            date = Date::ParseDate(dateStr);
			valid = true;
        }
        catch (std::string& e)
        {
            std::cerr << e << std::endl;
            valid = false;
        }
    } while (!valid);

    TripReservation* newTrip = new TripReservation(newRide ,*date);

    tripReservationList.push_back(*newTrip);

    return *newTrip;
}

// Add a new Trip Reservation provided as a reference
TripReservation& TaxiCompany::addTripReservation(TripReservation& newTrip) {
    tripReservationList.push_back(newTrip);
    std::cout << "Trip Reservation added successfully!" << std::endl;

    return newTrip;
}

// Add a new Delivery interactively
int TaxiCompany::addDelivery() {
	std::string product;
	double weight;
	TripReservation& newTrip = addTripReservation();
    std::cout << "Enter delivered product's description: ";
	std::getline(std::cin, product);
	std::cout << "Enter weight: ";
	std::cin >> weight;
	Delivery* newDelivery = new Delivery(newTrip, product, weight);
    DeliverysList.push_back(*newDelivery);

    return DeliverysList.size();
}
int TaxiCompany::addDelivery(Delivery& newDelivery) {
    DeliverysList.push_back(newDelivery);
    
	std::cout << "Delivery added successfully!" << std::endl;
    return DeliverysList.size();

}

// Print the details of the Taxi Company
void TaxiCompany::printTaxiCompany(TaxiCompany* pComp) {
    if (!pComp) {
        std::cerr << "TaxiCompany pointer is null!" << std::endl;
        return;
    }

    std::cout << "Taxi Company Name: " << pComp->getName() << std::endl;
    std::cout << "Address: " << pComp->getAddress() << std::endl;

    std::cout << "\nDrivers:\n";
    for (const auto& driver : pComp->getDriversArr()) {
        std::cout << *driver << std::endl; // Assuming Driver has an overloaded << operator
    }

    std::cout << "\nTaxis:\n";
    for (const auto& taxi : pComp->getTaxiArr()) {
        std::cout << *taxi << std::endl; // Assuming Taxi has an overloaded << operator
    }

    std::cout << "\nCustomers:\n";
    for (const auto& customer : pComp->getCustomerArr()) {
        std::cout << *customer << std::endl; // Assuming Customer has an overloaded << operator
    }

    pComp->printTripReservations();

    pComp->printDeliveries();
}

// Print all Rides
void TaxiCompany::printRides() const {
    std::cout << "All Rides:\n";
	for (const auto& driver : driversList) {
        std::cout << driver->getName() << "'s Rides:" << std::endl;
        driver->getRideList().print();
    }
}

// Print all Deliveries
void TaxiCompany::printDeliveries() const {
    std::cout << "Deliveries: Total " << this->DeliverysList.size() << " Deliveries" << std::endl;
    for (const auto& delivery : DeliverysList) {
        std::cout << delivery << std::endl; // Assuming Delivery has an overloaded << operator
    }
}

// Print all Trip Reservations
void TaxiCompany::printTripReservations() const {
	std::cout << "Trip Reservations: Total " << this->tripReservationList.size() << " Reservations " << std::endl;
    int i = 0;
    for (const auto& trip : tripReservationList) {
        i++;
		std::cout << "\nTrip Reservation #" << i << ":"<< std::endl;
        std::cout << trip << std::endl; // Assuming TripReservation has an overloaded << operator
    }
}

// Print all Drivers
void TaxiCompany::printDrivers() const {
	std::cout << "Drivers: Total " << this->driversList.size() << " Drivers" << std::endl;
	for (const auto& driver : driversList) {
		std::cout << *driver << std::endl; // Assuming Driver has an overloaded << operator
	}
}

// Print all Customers
void TaxiCompany::printCustomers() const {
	std::cout << "Customers: Total " << this->customerArr.size() << " Customers" << std::endl;
	for (const auto& customer : customerArr) {
		std::cout << *customer << std::endl; // Assuming Customer has an overloaded << operator
	}
}
// Print all Taxis  
void TaxiCompany::printTaxis() const {
    std::cout << "Taxis: Total " << this->taxiList.size() << " Taxis" << std::endl;
    for (const auto& taxi : taxiList) {
        std::cout << *taxi << std::endl; // Assuming Taxi has an overloaded << operator
    }
}

// Calculate and print the income of the company
void TaxiCompany::calculateIncome() const {
    double totalIncome = 0.0;

    for (const auto& trip : tripReservationList) {
        totalIncome += trip.getPayment().getPrice(); 
    }

    for (const auto& delivery : DeliverysList) {
        totalIncome += delivery.getPayment().getPrice(); // Assuming Payment has a getAmount() method
    }

    std::cout << "Total Income: $" << totalIncome << std::endl;
}

// Calculate and print the outcome of the company (e.g., expenses, costs)
void TaxiCompany::calculateOutcome() const {
    double totalOutcome = 0.0;

    // This could include salaries, maintenance, fuel, etc.
    // For simplicity, let's assume we're calculating salaries for drivers as an example
    for (const auto& driver : driversList) {
    //    totalOutcome += driver->calculateSalary(); // Assuming Driver has a calculateSalary() method
    }

    std::cout << "Total Outcome: $" << totalOutcome << std::endl;
}

bool TaxiCompany::isNumeric(const std::string& str)
{
    for (char c : str) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

bool TaxiCompany::isAlphabetic(const std::string& str)
{
    for (char c : str) {
        if (!std::isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}


/////////////
///Getters///
/////////////

list<Driver*> TaxiCompany::getDriversArr() const {
    return driversList;
}

list<Customer*> TaxiCompany::getCustomerArr() const {
    return customerArr;
}

list<Taxi*> TaxiCompany::getTaxiArr() const {
    return taxiList;
}

list<TripReservation> TaxiCompany::getTripReservationArr() const {
    return tripReservationList;
}

list<Delivery> TaxiCompany::getDeliverysArr() const {
    return DeliverysList;
}

const string& TaxiCompany::getName() const {
    return name;
}

const Address& TaxiCompany::getAddress() const {
    return address;
}

//////////////
/// Setters///
//////////////

bool TaxiCompany::setName(const string& newName) {
    if (newName.empty()) {
        return false; // Name should not be empty
    }
    name = newName;
    return true;
}

bool TaxiCompany::setAddress(const Address& newAddress) {
    address = newAddress;
    return true;
}

bool TaxiCompany::setDriversArr(const list<Driver*>& driversArr) {
    // Clear the existing list and delete the current drivers to avoid memory leaks
    for (Driver* driver : driversList) {
        delete driver;
    }
    driversList.clear();

    driversList = driversArr;
    return true;
}

bool TaxiCompany::setTaxiArr(const list<Taxi*>& taxiArr) {
    // Clear the existing list and delete the current taxis to avoid memory leaks
    for (Taxi* taxi : taxiList) {
        delete taxi;
    }
    taxiList.clear();

    taxiList = taxiArr;
    return true;
}

bool TaxiCompany::setCustomerArr( list<Customer*>& customerArr) {
    // Clear the existing list and delete the current customers to avoid memory leaks
    for (Customer* customer : customerArr) {
        delete customer;
    }
    customerArr.clear();

    customerArr = customerArr;
    return true;
}

bool TaxiCompany::setTripReservationArr(const list<TripReservation>& tripReservationArr) {
    tripReservationList = tripReservationArr;
    return true;
}

bool TaxiCompany::setDeliverysArr(const list<Delivery>& deliverysArr) {
    DeliverysList = deliverysArr;
    return true;
}


//Remove Driver
bool TaxiCompany::removeDriver() {
	std::string driverId;
	std::cout << "Enter driver's ID: ";
	std::cin >> driverId;
	return removeDriver(driverId);

}
bool TaxiCompany::removeDriver(const std::string& driverId) {
    for (auto it = driversList.begin(); it != driversList.end(); ++it) {
        if ((*it)->getId() == driverId) {
            std::cout << "Succesfully removed " << (*it)->getName() << " (ID:" << (*it)->getId() << ")"<<std::endl;
          //  delete* it;   // Free memory allocated for the Driver
            driversList.erase(it);   // Remove from the list
            
            return true;
        }
    }
    return false; // Driver not found
}
bool TaxiCompany::removeCustomer() {
	std::string customerId;
	std::cout << "Enter customer's ID: ";
	std::cin >> customerId;
	return removeCustomer(customerId);
}

bool TaxiCompany::removeCustomer(const std::string& customerId) {
    for (auto it = customerArr.begin(); it != customerArr.end(); ++it) {
        if ((*it)->getId() == customerId) {
          //  delete* it;   // Free memory allocated for the Customer
            customerArr.erase(it);   // Remove from the list
            return true;
        }
    }
    std::cout << "No customer with this ID" << std::endl;
    return false; // Customer not found
}

bool TaxiCompany::removeTaxi() {
	std::string vehicleNumber;
	std::cout << "Enter vehicle number: ";
	std::cin >> vehicleNumber;
	return removeTaxi(vehicleNumber);
}

bool TaxiCompany::removeTaxi(const std::string& vehicleNumber) {
	for (auto it = taxiList.begin(); it != taxiList.end(); ++it) {
		if ((*it)->getVehicleNumber() == vehicleNumber) {
			delete* it;   // Free memory allocated for the Taxi
			taxiList.erase(it);   // Remove from the list
			return true;
		}
	}
    std::cout << "No Taxi with this Vehicle Number" << std::endl;

	return false; // Taxi not found
}

//remove Trip Reservation
bool TaxiCompany::removeTripReservation() {
	int tripID;
	std::cout << "Enter Trip ID: ";
	std::cin >> tripID;
	return removeTripReservation(tripID);
}

bool TaxiCompany::removeTripReservation(int tripID) {
	for (auto it = tripReservationList.begin(); it != tripReservationList.end(); ++it) {
		if (it->getRideID() == tripID) {
			tripReservationList.erase(it);   // Remove from the list
			return true;
		}
	}
    std::cout << "No Trip Reservation with this Ride ID" << std::endl;
	return false; // Trip Reservation not found
}

//remove delivery
bool TaxiCompany::removeDelivery() {
	int deliveryID;
	std::cout
		<< "Enter Delivery ID: ";
	std::cin >> deliveryID;
	return removeDelivery(deliveryID);
}

bool TaxiCompany::removeDelivery(int deliveryID) {
	for (auto it = DeliverysList.begin(); it != DeliverysList.end(); ++it) {
		if (it->getRideID() == deliveryID) {
			DeliverysList.erase(it);   // Remove from the list
			return true;
		}
	}
    std::cout << "No Delivery with this Ride ID" << std::endl;
	return false; // Delivery not found
}

