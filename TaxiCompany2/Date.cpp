#include "Date.h"
#include <iostream>
// Constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

bool Date::operator==(const Date& other) const
{
	if (day == other.day && month == other.month && year == other.year)
		return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
	return os;
}

// Getters
const int Date::getDay() const {
    return day;
}

const int Date::getMonth() const {
    return month;
}

const int Date::getYear() const {
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

Date* Date::ParseDate(const char* dateStr) throw (const char*)
{
	// Parse the date string
	// The date string is in the format "dd/mm/yyyy"
	int day, month, year;
	if (sscanf(dateStr, "%d/%d/%d", &day, &month, &year) != 3 || (day > 31 || day < 1 || month>12 || month < 1 || year>2050 || year < 2024)) {
		throw "Invalid date format";
	}
    Date* date = new Date(day, month, year);
    return date;
}
