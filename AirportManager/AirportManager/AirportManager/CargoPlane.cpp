
#ifndef _CARGOPLANE_CPP
#define _CARGOPLANE_CPP
#include "CargoPlane.h"

CargoPlane::CargoPlane(int weightCapacity, int currentWeight, int fuelAmount, const char* model, State state,
    bool temperatureControlled, CargoType cargoType)
    : Airplane(weightCapacity, currentWeight, fuelAmount, model, state),
    temperatureControlled(temperatureControlled), cargoType(cargoType) {}

CargoPlane::CargoPlane(const CargoPlane& other)
    : Airplane(other), temperatureControlled(other.temperatureControlled), cargoType(other.cargoType) {}

CargoPlane::~CargoPlane() {}

// Assignment Operator
CargoPlane& CargoPlane::operator=(const CargoPlane& other) {
    if (this == &other) return *this; // Self-assignment check

    Airplane::operator=(other); // Assign base class parts
    temperatureControlled = other.temperatureControlled;
    cargoType = other.cargoType;

    return *this;
}

bool CargoPlane::isTemperatureControlled() const {
    return temperatureControlled;
}

void CargoPlane::setTemperatureControlled(bool temperatureControlled) {
    this->temperatureControlled = temperatureControlled;
}

CargoPlane::CargoType CargoPlane::getCargoType() const {
    return cargoType;
}

void CargoPlane::setCargoType(CargoType cargoType) {
    this->cargoType = cargoType;
}

void CargoPlane::display() const {
    Airplane::display();
    std::cout << "Temperature Controlled: " << (temperatureControlled ? "Yes" : "No") << std::endl;
    std::cout << "Cargo Type: ";
    switch (cargoType) {
    case Perishable: std::cout << "Perishable"; break;
    case NonPerishable: std::cout << "Non-Perishable"; break;
    case Hazardous: std::cout << "Hazardous"; break;
    case LiveAnimals: std::cout << "Live Animals"; break;
    case Oversized: std::cout << "Oversized"; break;
    }
    std::cout << std::endl;
}

// Interactive method to add cargo
void CargoPlane::addCargo() {
    int cargoTypeInt, cargoWeight;

    std::cout << "Enter cargo type (0: Perishable, 1: NonPerishable, 2: Hazardous, 3: LiveAnimals, 4: Oversized): ";
    std::cin >> cargoTypeInt;
    std::cout << "Enter cargo weight: ";
    std::cin >> cargoWeight;

    addCargo(static_cast<CargoType>(cargoTypeInt), cargoWeight);
}

// Non-interactive method to add cargo
void CargoPlane::addCargo(CargoType cargoType, int cargoWeight) {
    if (!temperatureControlled && (cargoType == Perishable || cargoType == LiveAnimals)) {
        throw std::invalid_argument("Cannot load perishable items or live animals into a non-temperature controlled plane.");
    }

    if (currentWeight + cargoWeight > weightCapacity) {
        throw std::overflow_error("Adding this cargo exceeds the plane's weight capacity.");
    }

    this->cargoType = cargoType;
    setCurrentWeight(currentWeight + cargoWeight);

    std::cout << "Cargo added successfully." << std::endl;
}
#endif 
