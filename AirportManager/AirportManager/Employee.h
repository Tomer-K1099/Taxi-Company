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
    Employee(const char* name, int age, const char* gender, const char* address, const char* phoneNumber,
                const int personalID , int employeeID, const char* position, double salary);

    Employee(const Employee& other);
    Employee(Employee&& other);
    ~Employee();
   

    Employee& operator=(const Employee& other);
    friend std::ostream& operator<<(std::ostream& os, const Employee& company); /*Print operator*/


    int getEmployeeID() const;
    void setEmployeeID(int employeeID);

    const char* getPosition() const;
    void setPosition(const char* position);

    double getSalary() const;
    void setSalary(double salary);

    void display() const override;
      
};

#endif