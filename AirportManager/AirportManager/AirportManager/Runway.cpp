#ifndef _RUNWAY_CPP
#define _RUNWAY_CPP

#include "Runway.h"

Runway::Runway(bool isClear) : isClear(isClear) {}

bool Runway::getIsClear() const {
    return isClear;
}

void Runway::setIsClear(bool isClear) {
    this->isClear = isClear;
}

void Runway::display() const {
    std::cout << "Runway is " << (isClear ? "clear" : "not clear") << std::endl;
}

#endif // !_RUNWAY_CPP
