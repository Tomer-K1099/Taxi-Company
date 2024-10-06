#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "Person.h"
#include <string>  



const int PHONE_NUMBER_SIZE = 10;

class Customer : public Person {

private:
    std::string phoneNumber;


public:
    // Constructors
    Customer(const std::string& name, const std::string& id, const std::string& phoneNumber);
	bool operator==(const Customer& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Customer& customer);

    //Setter
    bool setPhoneNumber(const std::string& phoneNumber);

    //Getter
    const std::string& getPhoneNumber() const;
};

#endif // CUSTOMER_H

