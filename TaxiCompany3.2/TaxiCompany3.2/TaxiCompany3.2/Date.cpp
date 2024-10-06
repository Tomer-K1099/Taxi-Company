#include "Date.h"
#include <iostream>
#include <sstream>

// Constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

// Comparison Operator
bool Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}

// Stream Output Operator
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return os;
}

// Getters
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

// Setters
bool Date::setDay(int d) {
    if (d < 1 || d > 31) {
        return false;  // Invalid day
    }
    day = d;
    return true;
}

bool Date::setMonth(int m) {
    if (m < 1 || m > 12) {
        return false;  // Invalid month
    }
    month = m;
    return true;
}

bool Date::setYear(int y) {
    year = y;
    return true;
}

// Static function to parse a date from a string
Date* Date::ParseDate(const std::string& dateStr) throw (const std::string&) {
    int day, month, year;
    char delimiter1, delimiter2;

    std::istringstream iss(dateStr);
    if (!(iss >> day >> delimiter1 >> month >> delimiter2 >> year) || delimiter1 != '/' || delimiter2 != '/' || 
        day < 1 || day > 31 || month < 1 || month > 12 || year < 2024 || year > 2050) {
        throw std::string("Invalid date format");
    }

    return new Date(day, month, year);
}
