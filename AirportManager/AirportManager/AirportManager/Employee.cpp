#ifndef _EMPLOYEE_CPP
#define _EMPLOYEE_CPP

#include "Employee.h"

Employee& Employee:: operator=(const Employee& other)
{
    if (this == &other) return *this; // Self-assignment check

    Person::operator=(other); // Assign base class parts
    delete[] position;

    // Allocate new resources and copy
    employeeID = other.employeeID;
    position = allocateAndCopy(other.position);
    salary = other.salary;

    return *this;
}

void Employee::display() const
{
    Person::display();
    std::cout << "Employee ID: " << employeeID << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
}
#endif // !_EMPLOYEE_CPP
