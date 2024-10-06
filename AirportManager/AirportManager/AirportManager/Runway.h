#ifndef _RUNWAY_H
#define _RUNWAY_H
#include <iostream>

class Runway
{
    private:
        bool isClear;

    public:
        Runway(bool isClear = true);

        bool getIsClear() const;

        void setIsClear(bool isClear);

        void display() const;

        friend std::istream& operator>>(std::istream& in, Runway runway)
        {
            in >> runway.isClear;
        }
};

#endif // !_RUNWAY_H
