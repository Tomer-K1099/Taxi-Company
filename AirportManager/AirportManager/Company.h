#ifndef _COMPANY_H
#define _COMPANY_H
#include "Employee.h"
#include <iostream>

    class Company {
    private:
        char* name;
        const int businessNumber;
        Employee** employees;
        int employeeCount;
        int employeeCapacity;

        char* allocateAndCopy(const char* str);

    public:
        Company(const char* name, const int businessNumber, const int count=0, const int capacity = 20);
        Company(const Company& other);
        Company(Company&& other);
        ~Company();

        Company& operator=(const Company& other); /*Assignment operator.*/
        Company& operator=(Company&& other); /*Move Assignment operator.*/
        bool operator==(const Company& other); /*Comaparison operator (based on businessNumber)*/
        Company& operator+=(const Employee* freshMeat); /*Add an employee operator*/

        const char* getName() const;
        void setName(const char* name);

        int getBusinessNumber() const;

        const int getEmployeeCapacity() const;
        void setEmployeeCapacity(const int capacity);

        Employee* getEmployees() const;
        void setEmployees(const Employee** employees);

        void addEmployee(const Employee& employee);
        void removeEmployee(int employeeID);

        void display() const;
    };



#endif // !_COMPANY_H
