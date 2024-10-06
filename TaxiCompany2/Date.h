#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {

private:
    int day;
    int month;
    int year;


public:
    Date(int d, int m, int y);        // Constructor

	bool operator==(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);

   
    // Getters
    const int getDay() const;
    const int getMonth() const;
    const int getYear() const;

    // Setters
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);

	static Date* ParseDate(const char* date) throw (const char*);
};

#endif // DATE_H
