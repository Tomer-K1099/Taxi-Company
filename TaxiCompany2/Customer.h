#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Person.h"

const int PHONE_NUMBER_SIZE = 10;

class Customer : public Person {

private:
    char phoneNumber[PHONE_NUMBER_SIZE + 1];

public:
    // Constructors
    Customer(const char* name, const char* id, const char* phoneNumber);

	bool operator==(const Customer& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Customer& customer);

    //Setter
    bool setPhoneNumber(const char* phoneNumber);

    //Getter
    const char* getPhoneNumber() const;
};

#endif // CUSTOMER_H

