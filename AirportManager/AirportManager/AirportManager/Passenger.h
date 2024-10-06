// Passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H

#include "Person.h"

class Passenger : public Person {
private:
    int passengerID;
    char* ticketNumber;
    char* flightNumber;

public:
    // Constructor
    Passenger(const char* name, int age, const char* gender, const char* address, const char* phoneNumber,
        int passengerID, const char* ticketNumber, const char* flightNumber);

    // Copy Constructor
    Passenger(const Passenger& other);

    // Destructor
    ~Passenger() override;

    // Assignment Operator
    Passenger& operator=(const Passenger& other);

    // Getter and Setter for passengerID
    int getPassengerID() const;
    void setPassengerID(int passengerID);

    // Getter and Setter for ticketNumber
    const char* getTicketNumber() const;
    void setTicketNumber(const char* ticketNumber);

    // Getter and Setter for flightNumber
    const char* getFlightNumber() const;
    void setFlightNumber(const char* flightNumber);

    // Method to display information about the passenger
    void display() const override;
};

#endif // PASSENGER_H
