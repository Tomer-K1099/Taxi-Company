#ifndef _PERSON_H
#define _PERSON_H
#include <iostream>
#include <cstring>

class Person {
protected:
    char* name;
    int age;
    char* gender;
    char* address;
    char* phoneNumber;

    // Helper function to allocate and copy string
    char* allocateAndCopy(const char* source);


public:
    Person(const char* name, int age, const char* gender, const char* address, const char* phoneNumber)
        : age(age) {
        this->name = allocateAndCopy(name);
        this->gender = allocateAndCopy(gender);
        this->address = allocateAndCopy(address);
        this->phoneNumber = allocateAndCopy(phoneNumber);
    }

    // Copy Constructor
    Person(const Person& other) {
        name = allocateAndCopy(other.name);
        age = other.age;
        gender = allocateAndCopy(other.gender);
        address = allocateAndCopy(other.address);
        phoneNumber = allocateAndCopy(other.phoneNumber);
    }

    virtual ~Person() {
        delete[] name;
        delete[] gender;
        delete[] address;
        delete[] phoneNumber;
    }

    // Assignment Operator
    Person& operator=(const Person& other);

    const char* getName() const {
        return name;
    }

    void setName(const char* name) {
        delete[] this->name;
        this->name = allocateAndCopy(name);
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    const char* getGender() const {
        return gender;
    }

    void setGender(const char* gender) {
        delete[] this->gender;
        this->gender = allocateAndCopy(gender);
    }

    const char* getAddress() const {
        return address;
    }

    void setAddress(const char* address) {
        delete[] this->address;
        this->address = allocateAndCopy(address);
    }

    const char* getPhoneNumber() const {
        return phoneNumber;
    }

    void setPhoneNumber(const char* phoneNumber) {
        delete[] this->phoneNumber;
        this->phoneNumber = allocateAndCopy(phoneNumber);
    }

    virtual void display() const;

};
#endif