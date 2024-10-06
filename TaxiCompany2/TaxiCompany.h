#ifndef TAXI_COMPANY_H
#define TAXI_COMPANY_H

#include "Address.h"
#include "Taxi.h"
#include "Customer.h"
#include "TripReservation.h"
#include "Delivery.h"
#include "PrivateTaxi.h"
#include "Minibus.h"
#include "Ride.h"
#include "Driver.h"

class TaxiCompany {

private:
    char* name;
    Address address;
    int driversCount;
    Driver** driversArr;
    int taxiCount;
    Taxi** taxiArr;
    int customerCount;
    Customer** customerArr;
    int tripReservationCount;
    TripReservation** tripReservationArr;
    int DeliverysCount;
    Delivery** DeliverysArr;

public:

    // Constructors
    TaxiCompany(const char* name, Address& address,
        int driversCount = 0, Driver** driversArr = nullptr,
        int taxiCount = 0, Taxi** taxiArr = nullptr,
        int customerCount = 0, Customer** customerArr = nullptr,
        int tripReservationCount = 0, TripReservation** tripReservationArr = nullptr,
        int DeliverysCount = 0, Delivery** DeliverysArr = nullptr) throw (const char*);
    TaxiCompany(const TaxiCompany& other) throw (const char*);         // Copy Constructor
    TaxiCompany(TaxiCompany&& other) noexcept;     // Move Constructor
    ~TaxiCompany();                                // Destructor

    TaxiCompany& operator=(const TaxiCompany& other);
    TaxiCompany& operator=(TaxiCompany&& other) noexcept;

    // Getters
    const char*                     getName() const;
    const Address&                  getAddress() const;
    const int                       getDriversCount() const;
    const Driver*const*             getDriversArr() const;
    const int                       getTaxiCount() const;
    const Taxi*const*               getTaxiArr() const;
    const int                       getCustomerCount() const;
    const Customer*const*           getCustomerArr() const;
    const int                       getTripReservationCount() const;
    const TripReservation*const*    getTripReservationArr() const;
    const int                       getDeliverysCount() const;
    const Delivery*const*           getDeliverysArr() const;

    // Setters
    bool setName(const char* name);
    bool setAddress(const Address& address);
    bool setDriversCount(int driversCount);
    bool setDriversArr( Driver** driversArr);
    bool setTaxiCount(int taxiCount);
    bool setTaxiArr(Taxi** taxi);
    bool setCustomerCount(int customerCount);
    bool setCustomerArr(Customer** customerArr);
    bool setTripReservationCount(int TripReservationCount);
    bool setTripReservationArr(TripReservation** TripReservationArr);
    bool setDeliverysCount(int deliverysCount);
    bool setDeliverysArr(Delivery** deliverysArr);

	int addTaxi();
    int addTaxi(Taxi& newTaxi);
    
    int addDriver();
    int addDriver(Driver& newDriver);

    int addCustomer();
	int addCustomer(Customer& newCustomer);

    Ride& addRide();
	Ride& addRide(Ride& newRide, Driver& driver);

    TripReservation& addTripReservation();
    TripReservation& addTripReservation(TripReservation& newTrip);

    int addDelivery();
	int addDelivery(Delivery& newDelivery);

    void calculateIncome() const;
    void calculateOutcome() const;

    void printRides() const;

   

    void printTaxiCompany(TaxiCompany& pComp);
    void printDeliveries() const;
    void printTripReservations() const;
    void printDrivers() const;
    void printCustomers() const;
    void printTaxis() const;

    Customer* findCustomer(const char* id);
    Driver* findDriver(const char* id);
};

#endif // TAXI_COMPANY_H

