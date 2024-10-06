// Passenger.h
#ifndef PASSENGER_H
#define PASSENGER_H

#include "Person.h"

class Airline;
class Passenger : public Person {
    
private:
    char* ticketNumber;
    char* flightNumber;
    bool hasBaggage;
    Airline& flyingWith; //which airline is this passenger flying with

public:
    Passenger(const char* name, const int age, const Gender gender, const char* address, const char* phoneNumber,
                        const int personalID, const char* ticketNumber, const char* flightNumber, Airline& flyingWith, const bool baggage=false);
    Passenger(const Passenger& other);
    Passenger(Passenger&& other);
    ~Passenger() override;


    Passenger& operator=(const Passenger& other); /*Assignment Operator*/
    Passenger& operator=(Passenger&& other); /*Move Assignment Operator*/

    friend std::ostream& operator<<(std::ostream& os, const Passenger& company); /*Print operator*/


    const char* getTicketNumber() const;
    void setTicketNumber(const char* ticketNumber);

    const char* getFlightNumber() const;
    void setFlightNumber(const char* flightNumber);

    void display() const override;
};

#endif // PASSENGER_H
