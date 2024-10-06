#ifndef _COMPANY_H
#define _COMPANY_H


#include "Employee.h"
#include <iostream>

    class Company {
    private:
        char* name;                 // Pointer to dynamically allocated name
        int businessNumber;         // Business number
        Employee* employees;        // dynamically allocated array of pointers to Employee objects
        int employeeCount;          // Current number of employees
        int employeeCapacity;       // Capacity of the employees array

  
    public:
        // Constructor
        Company(const char* name, int businessNumber, int capacity = 10);

        // Copy Constructor
        Company(const Company& other);

        // Destructor
        ~Company();

        // Copy Assignment Operator
        Company& operator=(const Company& other);

        // Move Constructor
        Company(Company&& other) noexcept;

        // Move Assignment Operator
        Company& operator=(Company&& other) noexcept;

        const char* getName() const;
        void setName(const char* name);

        int getBusinessNumber() const;
        void setBusinessNumber(int businessNumber);

        void addEmployee(const Employee& employee);
        void removeEmployee(int employeeID);

        void display() const;
    };



#endif // !_COMPANY_H
