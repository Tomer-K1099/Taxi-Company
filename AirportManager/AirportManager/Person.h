#ifndef _PERSON_H
#define _PERSON_H
#include <iostream>
#include <cstring>

class Person {
public:
    enum Gender
    {
        MALE,
        FEMALE
    };
protected:
    char* name;
    int age;
    Gender gender;
    char* address;
    char* phoneNumber;
    const int personalID;

    // Helper function to allocate and copy string
    char* allocateAndCopy(const char* source);

public:
    Person(const char* name, int age, Gender gender, const char* address, const char* phoneNumber, const int personalID);
    Person(const Person& other);
    Person(Person&& other);
    virtual ~Person();

    
    Person& operator=(const Person& other); /*Assignment Operator*/
    bool operator==(const Person& other);  /*Comparison Operator (based on ID)*/
    friend std::ostream& operator<<(std::ostream& os, const Person& person); /*Print operator*/


    const char* getName() const;

    void setName(const char* name);

    const int getAge() const;
    void setAge(const int age);

    const Gender getGender();
    void setGender(const Gender gender);

    const char* getAddress() const;
    void setAddress(const char* address);

    const char* getPhoneNumber() const;
    void setPhoneNumber(const char* phoneNumber);

    int getID() const;
   
    virtual void display() const;

};
#endif