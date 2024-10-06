#ifndef ADDRESS_H
#define ADDRESS_H

#include <cstring>
#include <iostream>
#include <string>  

class Address {

private:
    int num;
    std::string street;
    std::string city;

public:
    // Constructors
    Address(int n, const std::string& s, const std::string& c);

    bool operator==(const Address& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Address& address);

    // Getters
    int getNum() const;
    const std::string& getStreet() const;
    const std::string& getCity() const;

    // Setters
    bool setNum(int num);
    bool setStreet(const std::string& street);
    bool setCity(const std::string& city);

    static Address* parseAddress(const std::string& address) throw (std::string&);
};

#endif // ADDRESS_H
