#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>  


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
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);

	static Date* ParseDate(const std::string&  date) throw (const std::string& );
};

#endif // DATE_H
