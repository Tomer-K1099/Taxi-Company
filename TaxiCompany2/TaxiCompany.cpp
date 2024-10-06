#include "TaxiCompany.h"
#include <iostream>
#include <cstring>

#include "TaxiCompany.h"
#include <stdexcept>  // For std::runtime_error
#include <cstring>    // For strcpy

// Constructor
TaxiCompany::TaxiCompany(const char* name, Address& address, int driversCount, Driver** driversArr, int taxiCount,
    Taxi** taxiArr, int customerCount, Customer** customerArr, int tripReservationCount,
    TripReservation** tripReservationArr, int deliverysCount, Delivery** deliverysArr) throw (const char*)
    : address(address), driversCount(driversCount), taxiCount(taxiCount),
    customerCount(customerCount), tripReservationCount(tripReservationCount),
    DeliverysCount(deliverysCount),
    driversArr(nullptr), taxiArr(nullptr), customerArr(nullptr),
    tripReservationArr(nullptr), DeliverysArr(nullptr) {

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    // Deep copy of arrays
    if (driversCount > 0) {
        this->driversArr = new Driver * [driversCount];
        for (int i = 0; i < driversCount; ++i) {
            this->driversArr[i] = new Driver(*driversArr[i]);
        }
    }

    if (taxiCount > 0) {
        this->taxiArr = new Taxi * [taxiCount];
        for (int i = 0; i < taxiCount; ++i) {
            if (Minibus* minibus = dynamic_cast<Minibus*>(taxiArr[i])) {
                this->taxiArr[i] = new Minibus(*minibus);
            }
            else if (PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(taxiArr[i])) {
                this->taxiArr[i] = new PrivateTaxi(*privateTaxi);
            }
            else {
                throw "Unknown Taxi type";
            }
        }
    }

    if (customerCount > 0) {
        this->customerArr = new Customer*[customerCount];
        for (int i = 0; i < customerCount; ++i) {
            this->customerArr[i] = new Customer(*customerArr[i]);
        }
    }

    if (tripReservationCount > 0) {
        this->tripReservationArr = new TripReservation*[tripReservationCount];
        for (int i = 0; i < tripReservationCount; ++i) {
            this->tripReservationArr[i] = new TripReservation(*tripReservationArr[i]);
        }
    }

    if (DeliverysCount > 0) {
        this->DeliverysArr = new Delivery*[DeliverysCount];
        for (int i = 0; i < DeliverysCount; ++i) {
            this->DeliverysArr[i] = new Delivery(*deliverysArr[i]);
        }
    }
}

// Copy Constructor
TaxiCompany::TaxiCompany(const TaxiCompany& other) throw(const char*)
    : address(other.address), driversCount(other.driversCount), taxiCount(other.taxiCount),
    customerCount(other.customerCount), tripReservationCount(other.tripReservationCount),
    DeliverysCount(other.DeliverysCount), driversArr(nullptr), taxiArr(nullptr), customerArr(nullptr),
    tripReservationArr(nullptr), DeliverysArr(nullptr) {

    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    if (driversCount > 0) {
        this->driversArr = new Driver * [driversCount];
        for (int i = 0; i < driversCount; ++i) {
            this->driversArr[i] = new Driver(*other.driversArr[i]);
        }
    }

    if (taxiCount > 0) {
        this->taxiArr = new Taxi * [taxiCount];
        for (int i = 0; i < taxiCount; ++i) {
            if (Minibus* minibus = dynamic_cast<Minibus*>(other.taxiArr[i])) {
                this->taxiArr[i] = new Minibus(*minibus);
            }
            else if (PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(other.taxiArr[i])) {
                this->taxiArr[i] = new PrivateTaxi(*privateTaxi);
            }
            else {
                throw "Unknown Taxi type";
            }
        }
    }

    if (customerCount > 0) {
        this->customerArr = new Customer*[customerCount];
        for (int i = 0; i < customerCount; ++i) {
            this->customerArr[i] = new Customer(*other.customerArr[i]);
        }
    }

    if (tripReservationCount > 0) {
        this->tripReservationArr = new TripReservation*[tripReservationCount];
        for (int i = 0; i < tripReservationCount; ++i) {
            this->tripReservationArr[i] = new TripReservation(*other.tripReservationArr[i]);
        }
    }

    if (DeliverysCount > 0) {
        this->DeliverysArr = new Delivery*[DeliverysCount];
        for (int i = 0; i < DeliverysCount; ++i) {
            this->DeliverysArr[i] = new Delivery(*other.DeliverysArr[i]);
        }
    }
}

// Move Constructor
TaxiCompany::TaxiCompany(TaxiCompany&& other) noexcept
    : address(other.address), driversCount(other.driversCount), driversArr(other.driversArr),
    taxiCount(other.taxiCount), taxiArr(other.taxiArr), customerCount(other.customerCount),
    customerArr(other.customerArr), tripReservationCount(other.tripReservationCount),
    tripReservationArr(other.tripReservationArr), DeliverysCount(other.DeliverysCount),
    DeliverysArr(other.DeliverysArr), name(other.name) {

    // Nullify the moved-from object's pointers
    other.name = nullptr;
    other.driversArr = nullptr;
    other.taxiArr = nullptr;
    other.customerArr = nullptr;
    other.tripReservationArr = nullptr;
    other.DeliverysArr = nullptr;
}

// Destructor
TaxiCompany::~TaxiCompany() {
    delete[] name;
    for (int i = 0; i < driversCount; ++i) {
        delete driversArr[i];
    }
    delete[] driversArr;

    for (int i = 0; i < taxiCount; ++i) {
        delete taxiArr[i];
    }
    delete[] taxiArr;

    for (int i = 0; i < tripReservationCount; ++i) {
        delete tripReservationArr[i];
    }
    delete[] tripReservationArr;

    for (int i = 0; i < DeliverysCount; ++i) {
        delete DeliverysArr[i];
    }
    delete[] DeliverysArr;

    for (int i = 0; i < customerCount; ++i) {
        delete customerArr[i];
    }
    delete[] customerArr;
}

// Copy Assignment Operator
TaxiCompany& TaxiCompany::operator=(const TaxiCompany& other) {
    if (this != &other) {
        // Clean up existing resources
        delete[] name;
        for (int i = 0; i < driversCount; ++i) {
            delete driversArr[i];
        }
        delete[] driversArr;

        for (int i = 0; i < taxiCount; ++i) {
            delete taxiArr[i];
        }
        delete[] taxiArr;

        for (int i = 0; i < tripReservationCount; ++i) {
            delete tripReservationArr[i];
        }
        delete[] tripReservationArr;

        for (int i = 0; i < DeliverysCount; ++i) {
            delete DeliverysArr[i];
        }
        delete[] DeliverysArr;

        for (int i = 0; i < customerCount; ++i) {
            delete customerArr[i];
        }
        delete[] customerArr;

        // Invoke copy c'tor to perform deep copy
        TaxiCompany temp(other);


        std::swap(*this, temp);
    }
    return *this;

}

// Move Assignment Operator
TaxiCompany& TaxiCompany::operator=(TaxiCompany&& other) noexcept {
    if (this != &other) {
        delete[] name;
        for (int i = 0; i < driversCount; ++i) {
            delete driversArr[i];
        }
        delete[] driversArr;
        for (int i = 0; i < taxiCount; ++i) {
            delete taxiArr[i];
        }
        delete[] taxiArr;
        delete[] customerArr;
        delete[] tripReservationArr;
        delete[] DeliverysArr;

        name = other.name;
        address = other.address;
        driversCount = other.driversCount;
        taxiCount = other.taxiCount;
        customerCount = other.customerCount;
        tripReservationCount = other.tripReservationCount;
        DeliverysCount = other.DeliverysCount;

        // Set the other object to a valid state
        other.name = nullptr;
        other.driversArr = nullptr;
        other.taxiArr = nullptr;
        other.customerArr = nullptr;
        other.tripReservationArr = nullptr;
        other.DeliverysArr = nullptr;
    }
    return *this;
}

int TaxiCompany::addTaxi() {
    char vehicleNum[VEHICLE_NUMBER_SIZE + 1];
    char color[50];

    std::cout << "Enter taxi's vehicle number: ";
    std::cin.getline(vehicleNum, VEHICLE_NUMBER_SIZE + 1);
    std::cout << "Enter taxi's color: ";
    std::cin.getline(color, 50);

    std::cout << "Enter taxi's type:\n1. Minibus\n2. PrivateTaxi\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer

    Taxi* newTaxi = nullptr;

    if (choice == 1) {
        newTaxi = new Minibus(vehicleNum, color);  // Only passing vehicle number and color
    }
    else if (choice == 2) {
        newTaxi = new PrivateTaxi(vehicleNum, color);  // Only passing vehicle number and color
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        return 0;

    }
	return addTaxi(*newTaxi);

}

int TaxiCompany::addTaxi(Taxi& newTaxi) {
    // Resize the array to accommodate the new taxi 
    Taxi** tempTaxiArr = new Taxi * [taxiCount + 1];
    for (int i = 0; i < taxiCount; ++i) {
		if (Minibus* minibus = dynamic_cast<Minibus*>(taxiArr[i])) {
			tempTaxiArr[i] = new Minibus(*minibus);
		}
		else if (PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(taxiArr[i])) {
			tempTaxiArr[i] = new PrivateTaxi(*privateTaxi);
		}
    }
    if (Minibus* minibus = dynamic_cast<Minibus*>(&newTaxi)) {
        tempTaxiArr[taxiCount] = new Minibus(*minibus);
    }
    else if (PrivateTaxi* privateTaxi = dynamic_cast<PrivateTaxi*>(&newTaxi)) {
        tempTaxiArr[taxiCount] = new PrivateTaxi(*privateTaxi);
    }
    for (int i = 0; i < taxiCount; i++)
        delete taxiArr[i];
    delete taxiArr;

	std::swap(taxiArr, tempTaxiArr);
    taxiCount++;

    std::cout << "Taxi added successfully!" << std::endl;
    return 1;
}

int TaxiCompany::addDriver() {
    char name[50];
    char id[20];
    char licenseNumber[LICENSE_NUMBER_SIZE + 1];
    int taxiChoice;

	if (getTaxiArr() == nullptr || getTaxiCount() == 0) {
		std::cout << "No taxis available. Please add a taxi first." << std::endl;
		return 0;
	}
    std::cout << "Enter driver's name: ";
    std::cin.getline(name, 50);

    std::cout << "Enter driver's ID: ";
    std::cin.getline(id, 20);

    std::cout << "Enter driver's license number: ";
    std::cin.getline(licenseNumber, LICENSE_NUMBER_SIZE + 1);

    std::cout << "Choose a taxi for this driver: " <<std::endl;
    for (int i = 0; i < taxiCount; i++) {
        std::cout << "[" << i << "] " << *taxiArr[i] << std::endl;
    }
    std::cin >> taxiChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    Driver newDriver(*taxiArr[taxiChoice], name, id, licenseNumber, 0, nullptr);

    return addDriver(newDriver);
}

    // Add newDriver to the drivers array
int TaxiCompany::addDriver(Driver& newDriver) {
        Driver** tempDriversArr = new Driver * [driversCount + 1];
        for (int i = 0; i < driversCount; ++i) 
            tempDriversArr[i] = new Driver(*driversArr[i]);
        
        for (int i = 0; i < driversCount; i++)
            delete driversArr[i];
        delete [] driversArr;

        tempDriversArr[driversCount] = new Driver (newDriver);


		std::swap(driversArr, tempDriversArr);  // Swap the new array with the old one
        driversCount++;

        std::cout << "Driver added successfully!" << std::endl;
        return 1;
    }




int TaxiCompany::addCustomer() {
    char name[50];
    char id[20];
    char phone[15];

    std::cout << "Enter customer's name: ";
    std::cin.getline(name, 50);

    std::cout << "Enter customer's ID: ";
    std::cin.getline(id, 20);

    std::cout << "Enter customer's phone number: ";
    std::cin.getline(phone, 15);

    // Create the new Customer object
    Customer newCustomer(id, name, phone);

	return addCustomer(newCustomer);
}

int TaxiCompany::addCustomer(Customer& newCustomer) {
    // Add newCustomer to the customers array
        Customer** tempCustomerArr = new Customer*[customerCount + 1];
        for (int i = 0; i < customerCount; ++i) {
            tempCustomerArr[i] = new Customer(*customerArr[i]);
        }
        for (int i= 0;  i<customerCount; i++)
        {
            delete customerArr[i];
        }
		delete[] customerArr;
        
		tempCustomerArr[customerCount] = new Customer(newCustomer);  // Move the new customer to the last element of the array

		std::swap(customerArr, tempCustomerArr);  // Swap the new array with the old one
        customerCount++;
    
	
    std::cout << "Customer added successfully!" << std::endl;
    return 1;
}


Ride& TaxiCompany::addRide() {
    int rideId, time, passengers;
    double price;
    char originAddressStr[100];
    char destAddressStr[100];
	int driverChoice , custChoice;
	Driver* driver = nullptr;
	Customer* customer = nullptr;

    // Input details for the ride
    std::cout << "Enter ride's ID: ";
    std::cin >> rideId;

    do {
        std::cout << "Choose the driver: " << std::endl;
        for (int i = 0; i < driversCount; i++)
        {
            std::cout << "[" << i << "] " << std::endl << *driversArr[i] << std::endl;
        }
        std::cin >> driverChoice;
    } while (driverChoice < 0 || driverChoice >= driversCount);
	driver = driversArr[driverChoice];

    do {
        std::cout << "Choose the customer: ";
        for (int i = 0; i < customerCount; i++)
        {
            std::cout << "[" << i << "] " << std::endl << *customerArr[i] << std::endl;
        }
        std::cin >> custChoice;
    } while (custChoice < 0 || custChoice >= customerCount);
	customer = customerArr[custChoice];

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool correctAddress = true;
    Address* originAddress =nullptr, *destAddress =nullptr;
    do {
        try {
            std::cout << "Enter the origin address (e.g., 123 Main St, Springfield): ";
            std::cin.getline(originAddressStr, 100);
            originAddress = Address::parseAddress(originAddressStr);
            correctAddress = true;
        }
        catch (const char* msg) {
                std::cout << msg << std::endl;
                correctAddress = false;
        }
    } while (!correctAddress);
    do{
        try{
            std::cout << "Enter the destination address (e.g., 456 Elm St, Springfield): ";
            std::cin.getline(destAddressStr, 100);
            destAddress = Address::parseAddress(destAddressStr);
            correctAddress = true;
        }
        catch (const char* msg) {
            std::cout << msg << std::endl;
            correctAddress = false;
        }
	} while (!correctAddress);
   
    
    std::cout << "Enter the ride time (in minutes): ";
    std::cin >> time;

    do {
        std::cout << "Enter the number of passengers: ";
        std::cin >> passengers;
    } while (passengers <= 0 || passengers > driver->getTaxi().getMaxPassengers());  // Validate the number of passengers

    price = 20 + time * 2.0 + (passengers > 4 ? 3 * passengers : 0);  // 20 base price + 2 per minute. Minibus costs extra 3 per passenger.

    int payChoice;
    do {
        std::cout << "Enter the payment method:\n1. Cash\n2. Credit\n";
        std::cin >> payChoice;
    } while (payChoice != 1 && payChoice != 2);

    Payment payment(payChoice == 1 ? Cash : Credit, price);  // Use the default constructor; modify as needed for actual payment details
    // Create a new Ride object
    Ride newRide (*driver, *customer, rideId, passengers, time, *originAddress, *destAddress, payment);

    return addRide(newRide, *driver);
    
}

Ride& TaxiCompany::addRide(Ride& newRide, Driver& driver) {
        return driver.addRide(newRide);
}

TripReservation& TaxiCompany::addTripReservation(){
    Ride& newRide = addRide(); //returns a pointer to the last ride in driver's Ride array
	
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clean buffer

	char dateStr[11];
    bool valid = false;
    Date* date = nullptr;
    while (!valid) {
        try {
            std::cout << "Enter the date (DD/MM/YYYY): ";
            std::cin.getline(dateStr, 50);
            date = Date::ParseDate(dateStr);
            valid = true;
        }
        catch (const char* msg) {
            std::cout<< msg;
            valid = false;
        }
        
    }
    // Create a new TripReservation object
    TripReservation newTrip(newRide, *date);

	return addTripReservation(newTrip);

}

TripReservation& TaxiCompany::addTripReservation(TripReservation& newTrip) {
    // Create a temporary array with an additional space for the new trip reservation
    TripReservation** tempTripReservationArr = new TripReservation*[tripReservationCount + 1];

    // Copy existing trip reservations to the new array
    for (int i = 0; i < tripReservationCount; i++) 
        tempTripReservationArr[i] = new TripReservation(*tripReservationArr[i]);
    
    for (int i = 0; i < tripReservationCount; i++)
        delete tripReservationArr[i];
	delete[] tripReservationArr;
	

    // Add the new trip reservation to the array
    tempTripReservationArr[tripReservationCount] = new TripReservation(newTrip);

	
    // Assign the new array back to tripReservationArr
	std::swap(tripReservationArr, tempTripReservationArr);
    tripReservationCount++;

    std::cout << "Trip reservation added successfully!" << std::endl;
    return *tripReservationArr[tripReservationCount - 1];

}




int TaxiCompany::addDelivery() {
    char product[50];
    double weight;

    TripReservation& newTrip = addTripReservation();

    std::cout << "Enter the product name: ";
    std::cin.getline(product, 50);

    do {
        std::cout << "Enter the weight of the product: ";
        std::cin >> weight;
    } while (weight <= 0 || weight > MAX_WEIGHT);  // Validate the weight

    // Create a new Delivery object
    Delivery newDelivery(newTrip, product, weight);
    
	return addDelivery(newDelivery);
}

int TaxiCompany::addDelivery(Delivery& newDelivery) {
	 // Create a temporary array with an additional space for the new delivery
    Delivery** tempDeliveryArr = new Delivery*[DeliverysCount + 1];

    // Copy existing deliveries to the new array
    for (int i = 0; i < DeliverysCount; i++) 
        tempDeliveryArr[i] = new Delivery(*DeliverysArr[i]);
    
    // Clean up old array
    for (int i = 0; i < DeliverysCount; i++)
        delete DeliverysArr[i];
    delete[] DeliverysArr;

    // Add the new delivery to the array
    tempDeliveryArr[DeliverysCount] = new Delivery(newDelivery);

    // Assign the new array back to DeliverysArr
	std::swap(DeliverysArr, tempDeliveryArr);
    DeliverysCount++;

    std::cout << "Delivery added successfully!" << std::endl;
    return 1;
}


void TaxiCompany::printTaxiCompany(TaxiCompany& pComp) {

    std::cout << "Taxi Company Name: " << pComp.getName() << std::endl;
    std::cout << "Address: " << pComp.getAddress() << std::endl;

    std::cout << "Number of Drivers: " << pComp.getDriversCount() << std::endl;
    for (int i = 0; i < pComp.getDriversCount(); i++) {
        if (pComp.getDriversArr()[i] != nullptr) {
            std::cout << "Driver " << i + 1 << ": " << std::endl << *(pComp.getDriversArr()[i]) << std::endl;
        }
    }

    std::cout << "Number of Taxis: " << pComp.getTaxiCount() << std::endl;
    for (int i = 0; i < pComp.getTaxiCount(); i++) {
        if (pComp.getTaxiArr()[i] != nullptr) {
            std::cout << "Taxi " << i + 1 << ": " << std::endl << *(pComp.getTaxiArr()[i]) << std::endl;
        }
    }

    std::cout << "Number of Customers: " << pComp.getCustomerCount() << std::endl;
    for (int i = 0; i < pComp.getCustomerCount(); i++) {
        std::cout << "Customer " << i + 1 << ": " << std::endl << *pComp.getCustomerArr()[i] << std::endl;
    }

    std::cout << "Number of Trip Reservations: " << pComp.getTripReservationCount() << std::endl;
    for (int i = 0; i < pComp.getTripReservationCount(); i++) {
        std::cout << "Trip Reservation " << i + 1 << ": " << std::endl << *pComp.getTripReservationArr()[i] << std::endl;
    }

    std::cout << "Number of Deliveries: " << pComp.getDeliverysCount() << std::endl;
    for (int i = 0; i < pComp.getDeliverysCount(); i++) {
        std::cout << "Delivery " << i + 1 << ": " << std::endl << *pComp.getDeliverysArr()[i] << std::endl;
    }
}
   
Driver* TaxiCompany::findDriver(const char* id) {
    for (int i = 0; i < driversCount; ++i) {
        if (strcmp(driversArr[i]->getId(), id) == 0) {
            return driversArr[i];
        }
    }
    return nullptr;  // Driver not found
}

Customer* TaxiCompany::findCustomer(const char* id) {
    for (int i = 0; i < customerCount; ++i) {
        if (strcmp(customerArr[i]->getId(), id) == 0) {
            return customerArr[i];
        }
    }
    return nullptr;  // Customer not found
}



//Getters
const char* TaxiCompany::getName() const {
	return name;
}

const Address& TaxiCompany::getAddress() const {
	return this->address;
}

const int TaxiCompany::getDriversCount() const {
	return driversCount;
}

const Driver*const* TaxiCompany::getDriversArr() const {
    return driversArr;
}

const int TaxiCompany::getTaxiCount() const {
	return taxiCount;
}

const Taxi* const* TaxiCompany::getTaxiArr() const {
    return (taxiArr);
}

const int TaxiCompany::getCustomerCount() const {
	return customerCount;
}

const Customer* const* TaxiCompany::getCustomerArr() const {
    return customerArr;
}

const int TaxiCompany::getTripReservationCount() const {
	return tripReservationCount;
}

const TripReservation* const* TaxiCompany::getTripReservationArr() const {
    return (tripReservationArr);
}

const int TaxiCompany::getDeliverysCount() const {
	return DeliverysCount;
}

const Delivery* const* TaxiCompany::getDeliverysArr() const {
    return DeliverysArr;
}

//Setters

bool TaxiCompany::setName(const char* name) {
	if (name == nullptr) {
		return false;
	}
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	return true;
}

bool TaxiCompany::setAddress(const Address& address) {
	this->address = address;
	return true;
}

bool TaxiCompany::setDriversCount(int driversCount) {
	if (driversCount < 0) {
		return false;
	}
	this->driversCount = driversCount;
	return true;
}

bool TaxiCompany::setDriversArr( Driver** driversArr) {
	if (driversArr == nullptr) {
		return false;
	}
	this->driversArr = driversArr;
	return true;
}

bool TaxiCompany::setTaxiCount(int taxiCount) {
	if (taxiCount < 0) {
		return false;
	}
	this->taxiCount = taxiCount;
	return true;
}

bool TaxiCompany::setTaxiArr(Taxi** taxiArr) {
	if (taxiArr == nullptr) {
		return false;
	}
	this->taxiArr = taxiArr;
	return true;
}

bool TaxiCompany::setCustomerCount(int customerCount) {
	if (customerCount < 0) {
		return false;
	}
	this->customerCount = customerCount;
	return true;
}

bool TaxiCompany::setCustomerArr(Customer** customerArr) {
	if (customerArr == nullptr) {
		return false;
	}
	this->customerArr = customerArr;
	return true;
}

bool TaxiCompany::setTripReservationCount(int tripReservationCount) {
	if (tripReservationCount < 0) {
		return false;
	}
	this->tripReservationCount = tripReservationCount;
	return true;
}

bool TaxiCompany::setTripReservationArr(TripReservation** tripReservationArr) {
	if (tripReservationArr == nullptr) {
		return false;
	}
	this->tripReservationArr = tripReservationArr;
	return true;
}

bool TaxiCompany::setDeliverysCount(int DeliverysCount) {
	if (DeliverysCount < 0) {
		return false;
	}
	this->DeliverysCount = DeliverysCount;
	return true;
}

bool TaxiCompany::setDeliverysArr(Delivery** DeliverysArr) {
	if (DeliverysArr == nullptr) {
		return false;
	}
	this->DeliverysArr = DeliverysArr;
	return true;
}
void TaxiCompany::calculateIncome() const {
    double totalIncome = 0.0;

    // Calculate income from rides
    for (int i = 0; i < driversCount; ++i) {
        Driver* driver = driversArr[i];
        if (driver != nullptr) {
            const Ride*const* rideArr = driver->getRide();
            int rideCount = driver->getRideCount();
            for (int j = 0; j < rideCount; ++j) {
                if (rideArr[j] != nullptr) {
                    totalIncome += rideArr[j]->getPayment().getPrice();
                }
            }
        }
    }

    // Calculate income from trip reservations
    for (int i = 0; i < tripReservationCount; ++i) {
        totalIncome += tripReservationArr[i]->getPayment().getPrice();
    }

    // Calculate income from deliveries
    for (int i = 0; i < DeliverysCount; ++i) {
        totalIncome += DeliverysArr[i]->getPayment().getPrice();
    }

    std::cout << "Total Income: " << totalIncome << std::endl;
}

void TaxiCompany::calculateOutcome() const {
    double totalOutcome = 0.0;
    double driverSalary = 3000.0;  // Example fixed monthly salary for each driver
    double taxiMaintenanceCost = 500.0;  // Example fixed monthly maintenance cost for each taxi

    // Calculate total salaries for drivers
    totalOutcome += driversCount * driverSalary;

    // Calculate total maintenance costs for taxis
    totalOutcome += taxiCount * taxiMaintenanceCost;


    std::cout << "Total Outcome: $" << totalOutcome << std::endl;
}
void TaxiCompany::printRides() const {
    std::cout << "Rides Information:" << std::endl;

    bool anyRidesPrinted = false;

    for (int i = 0; i < driversCount; ++i) {
        Driver* driver = driversArr[i];

        if (driver != nullptr) {
            const Ride*const* rideArr = driver->getRide();
            int rideCount = driver->getRideCount();

            if (rideCount == 0) {
                std::cout << "Driver: " << driver->getName() << " has no rides." << std::endl;
                continue;
            }

            std::cout << "Driver: " << driver->getName() << " has " << rideCount << " ride(s)." << std::endl;

            for (int j = 0; j < rideCount; ++j) {
                if (rideArr[j] != nullptr) {
                    std::cout << "Ride " << j + 1 << ": " << std::endl;
                    std::cout << *rideArr[j] << std::endl;
                    anyRidesPrinted = true;
                }
                else {
                    std::cout << "Ride " << j + 1 << " is null." << std::endl;
                }
            }
        }
    }

    if (!anyRidesPrinted) {
        std::cout << "No rides available to display." << std::endl;
    }

	std::cin.ignore();  // Clear the input buffer
}

void TaxiCompany::printDeliveries() const {
    if (DeliverysCount == 0) {
        std::cout << "No deliveries available." << std::endl;
        return;
    }

    std::cout << "Deliveries Information:" << std::endl;
    for (int i = 0; i < DeliverysCount; ++i) {
        std::cout << "Delivery " << i + 1 << ": " << *DeliverysArr[i] << std::endl;
    }
}

void TaxiCompany::printTripReservations() const {
    if (tripReservationCount == 0) {
        std::cout << "No trip reservations available to display." << std::endl;
        return;
    }

    std::cout << "Trip Reservations Information:" << std::endl;
    for (int i = 0; i < tripReservationCount; ++i) {
        std::cout << "Trip Reservation " << i + 1 << ": " << std::endl;
        std::cout << *tripReservationArr[i] << std::endl;  // Assuming TripReservation class has an overloaded operator<<
    }
}

// print all the drivers
void TaxiCompany::printDrivers() const {
	if (driversCount == 0) {
		std::cout << "No drivers available." << std::endl;
		return;
	}

	std::cout << "Drivers Information:" << std::endl;
	for (int i = 0; i < driversCount; ++i) {
		std::cout << "Driver " << i + 1 << ": " << std::endl;
		std::cout << *driversArr[i] << std::endl;  
	}
}

// print all the customers
void TaxiCompany::printCustomers() const {
	if (customerCount == 0) {
		std::cout << "No customers available." << std::endl;
		return;
	}

	std::cout << "Customers Information:" << std::endl;
	for (int i = 0; i < customerCount; ++i) {
		std::cout << "Customer " << i + 1 << ": " << std::endl;
		std::cout << *customerArr[i] << std::endl;  
	}
}

//print all the taxis
void TaxiCompany::printTaxis() const {
	if (taxiCount == 0) {
		std::cout << "No taxis available." << std::endl;
		return;
	}

	std::cout << "Taxis Information:" << std::endl;
	for (int i = 0; i < taxiCount; ++i) {
		std::cout << "Taxi " << i + 1 << ": " << std::endl;
		std::cout << *taxiArr[i] << std::endl; 
	}
}