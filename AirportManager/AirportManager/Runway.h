#ifndef _RUNWAY_H
#define _RUNWAY_H
#include <iostream>
/*
A class that represents the runway in an airport from which an aircraft departs and lands.
Aircrafts can land or depart from a runway only when it's clear. 
Runway has no intuitive operator overloading.
*/

class Runway
{
    private:
        const int number;
        bool isClear;

    public:
        Runway(bool isClear = true);
        Runway(const Runway& other);
        Runway(Runway&& other);

        bool getIsClear() const;
        void setIsClear(const bool isClear);

        void display() const;
};


#endif // !_RUNWAY_H
