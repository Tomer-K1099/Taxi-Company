#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <iostream>
#include <cstring>
#include "Person.h"

class Employee : public Person {
private:
    int employeeID;
    char* position;
    double salary;

public:
    // Constructor
    Employee(const char* name, int age, const char* gender, const char* address, const char* phoneNumber,
        int employeeID, const char* position, double salary)
        : Person(name, age, gender, address, phoneNumber), employeeID(employeeID), salary(salary) {
        this->position = allocateAndCopy(position);
    }

    // Copy Constructor
    Employee(const Employee& other)
        : Person(other), employeeID(other.employeeID), salary(other.salary) {
        position = allocateAndCopy(other.position);
    }

    // Destructor
    ~Employee() {
        delete[] position;
    }
    //Move Constructor
    Employee(Employee&& other);

    // Assignment Operator
    Employee& operator=(const Employee& other);
       

    int getEmployeeID() const {
        return employeeID;
    }

    void setEmployeeID(int employeeID) {
        this->employeeID = employeeID;
    }

    const char* getPosition() const {
        return position;
    }

    void setPosition(const char* position) {
        delete[] this->position;
        this->position = allocateAndCopy(position);
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double salary) {
        this->salary = salary;
    }

    void display() const override;
      
    
};

#endif