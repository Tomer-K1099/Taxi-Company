#ifndef _COMPANY_CPP
#define _COMPANY_CPP
#include "Company.h"

//  function to allocate and copy string
char* Company::allocateAndCopy(const char* str) {
    if (str == nullptr) return nullptr;
    char* copy = new char[strlen(str) + 1];
   strcpy(copy, str);
   return copy;
}

// Utility function to resize the employees array
void Company::resizeEmployeesArray(int newCapacity) {
    Employee** newEmployees = new Employee * [newCapacity];
    for (int i = 0; i < employeeCount; ++i) {
        newEmployees[i] = employees[i];
    }
    delete[] employees;
    employees = newEmployees;
    employeeCapacity = newCapacity;
}

// Constructor
Company::Company(const char* name, int businessNumber, int capacity)
    : name(allocateAndCopy(name)), businessNumber(businessNumber), employeeCount(0), employeeCapacity(capacity) {
    employees = new Employee * [employeeCapacity];
}

// Copy Constructor
Company::Company(const Company& other)
    : name(allocateAndCopy(other.name)), businessNumber(other.businessNumber), employeeCount(other.employeeCount), employeeCapacity(other.employeeCapacity) {
    employees = new Employee * [employeeCapacity];
    for (int i = 0; i < employeeCount; ++i) {
        employees[i] = new Employee(*other.employees[i]);
    }
}

// Destructor
Company::~Company() {
    delete[] name;
    for (int i = 0; i < employeeCount; ++i) {
        delete employees[i];
    }
    delete[] employees;
}

// Assignment Operator
Company& Company::operator=(const Company& other) {
    if (this == &other) return *this; // Self-assignment check

    delete[] name;
    for (int i = 0; i < employeeCount; ++i) {
        delete employees[i];
    }
    delete[] employees;

    name = allocateAndCopy(other.name);
    businessNumber = other.businessNumber;
    employeeCount = other.employeeCount;
    employeeCapacity = other.employeeCapacity;

    employees = new Employee * [employeeCapacity];
    for (int i = 0; i < employeeCount; ++i) {
        employees[i] = new Employee(*other.employees[i]);
    }

    return *this;
}

const char* Company::getName() const {
    return name;
}

void Company::setName(const char* name) {
    delete[] this->name;
    this->name = allocateAndCopy(name);
}

int Company::getBusinessNumber() const {
    return businessNumber;
}

void Company::setBusinessNumber(int businessNumber) {
    this->businessNumber = businessNumber;
}

void Company::addEmployee(const Employee& employee) {
    if (employeeCount >= employeeCapacity) {
        resizeEmployeesArray(employeeCapacity * 2);
    }
    employees[employeeCount++] = new Employee(employee);
}

void Company::removeEmployee(int employeeID) {
    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i]->getEmployeeID() == employeeID) {
            delete employees[i];
            for (int j = i; j < employeeCount - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            --employeeCount;
            return;
        }
    }
    std::cerr << "Employee with ID " << employeeID << " not found." << std::endl;
}

void Company::display() const 
{
    std::cout << "Company Name: " << name << std::endl;
    std::cout << "Business Number: " << businessNumber << std::endl;
    std::cout << "Employees: " << std::endl;
    for (int i = 0; i < employeeCount; ++i)
    {
        employees[i]->display();
        std::cout << std::endl;
    }
}
#endif // !_COMPANY_CPP
