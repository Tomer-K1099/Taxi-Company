#ifndef TAXICOMPANY_H
#define TAXICOMPANY_H

#include <string>
#include "Address.h"
#include "Driver.h"
#include "Taxi.h"
#include "Customer.h"
#include "TripReservation.h"
#include "Delivery.h"
#include "Minibus.h"
#include "PrivateTaxi.h"
#include "TaxiFactory.h"
#include "MinibusFactory.h"
#include "PrivateTaxiFactory.h"
#include <string>  
#include <list>
#include <regex>

using namespace std;

//Singleton Class (Singleton design pattern) - The program supports only one TaxiCompany.
//Client Class (Factory Method design pattern) - The TaxiCompany class is the client class that creates Taxi objects.
class TaxiCompany {
private:
    string name;
    Address address;
    list<Driver*> driversList;
    list<Taxi*> taxiList;
    list<Customer*> customerArr;
    list<TripReservation> tripReservationList;
    list<Delivery> DeliverysList;

    TaxiCompany(const std::string& name, const Address& address,
        const std::list<Driver*>& driversArr = {},
        const std::list<Taxi*>& taxiArr = {},
        const std::list<Customer*>& customerArr = {},
        const std::list<TripReservation>& tripReservationArr = {},
        const std::list<Delivery>& deliverysArr = {});

    ~TaxiCompany();

	static TaxiCompany* instance; //Singleton instance

public:
    TaxiCompany(const TaxiCompany&) = delete;
    TaxiCompany& operator=(const TaxiCompany& ) = delete;

    static TaxiCompany& getInstance();
    int addTaxi();
    int addTaxi(TaxiFactory* factory, const std::string& vehicleNumber, const std::string& color);
    //int addTaxi(Taxi* newTaxi);
    int addDriver();
    int addDriver(Driver* newDriver);
    int addCustomer();
    int addCustomer(Customer* newCustomer);
    Ride& addRide() throw (std::string&);
    Ride& addRide(Ride& newRide, Driver& driver) throw(std::string&);
    TripReservation& addTripReservation();
    TripReservation& addTripReservation(TripReservation& newTrip);
    int addDelivery();
    int addDelivery(Delivery& newDelivery);

    PrivateTaxi* displayPrivateTaxis() const;
    Minibus* displayMinibuses() const;
    void printTaxiCompany(TaxiCompany* pComp);
    void printRides() const;
    void printDeliveries() const;
    void printTripReservations() const;
    void printDrivers() const;
    void printCustomers() const;
    void printTaxis() const;
    void calculateIncome() const;
    void calculateOutcome() const;

    static bool isNumeric(const std::string& str);
    static bool isAlphabetic(const std::string& str);

    Driver* findDriver(const string id);
    Customer* findCustomer(const string id);

    //Getters
    list<Driver*> getDriversArr() const;
    list <Customer*> getCustomerArr() const;
    list  <Taxi*> getTaxiArr() const;
    list<TripReservation> getTripReservationArr() const;
    list<Delivery> getDeliverysArr() const;
    const string& getName() const;
    const Address& getAddress() const;
   
    //Setters
    bool setName(const string& name);
    bool setAddress(const Address& address);
    bool setDriversArr(const list<Driver*>& driversArr);
    bool setTaxiArr(const list<Taxi*>& taxiArr);
    bool setCustomerArr(list<Customer*>& customerArr);
    bool setTripReservationArr(const list<TripReservation>& tripReservationArr);
    bool setDeliverysArr(const list<Delivery>& deliverysArr);


    bool removeDriver();
    bool removeDriver(const std::string& driverId);
    bool removeTaxi(const std::string& vehicleNumber);
    bool removeCustomer();

    bool removeTaxi();
    bool removeCustomer(const std::string& customerId);
    bool removeTripReservation();
    bool removeTripReservation(int tripID);
    bool removeDelivery();
    bool removeDelivery(int deliveryID);
   








};


#endif // TAXICOMPANY_H
