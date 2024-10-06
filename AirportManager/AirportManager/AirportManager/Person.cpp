#ifndef _PERSON_CPP
#define _PERSON_CPP

#include "Person.h"


char* allocateAndCopy(const char* source)
{
    char* dest = new char[strlen(source) + 1];
    strcpy(dest, source);
    return dest;
}

Person& Person::operator=(const Person& other)
{
    if (this == &other) return *this; // Self-assignment check

    delete[] name;
    delete[] gender;
    delete[] address;
    delete[] phoneNumber;

    // Allocate new resources and copy
    name = allocateAndCopy(other.name);
    age = other.age;
    gender = allocateAndCopy(other.gender);
    address = allocateAndCopy(other.address);
    phoneNumber = allocateAndCopy(other.phoneNumber);

    return *this;
}

void Person::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
}
#endif // !_PERSON_H
