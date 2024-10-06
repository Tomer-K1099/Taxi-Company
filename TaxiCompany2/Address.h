#ifndef ADDRESS_H
#define ADDRESS_H

#include <cstring>
#include <iostream>

class Address {

private:
    int num;
    char* street;
    char* city;


public:
    // Constructors
    Address(int n, const char* s, const char* c);
    Address(const Address& other);        // Copy Constructor
    Address(Address&& other);            // Move Constructor
    ~Address();                         // Destructor

    const Address& operator=(const Address& other);  
    const Address& operator=(Address&& other) noexcept;

	bool operator==(const Address& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Address& address);

    // Getters
    const int getNum() const;
    const char* getStreet() const;
    const char* getCity() const;

    // Setters
    bool setNum(int num);
    bool setStreet(const char* street);
    bool setCity(const char* city);

	static Address* parseAddress(const char* address) throw (const char*);

};

#endif // ADDRESS_H
