#ifndef _AIRPLANE_CPP
#define _AIRPLANE_CPP
#include "Airplane.h"

// Helper function to allocate and copy string
char* Airplane::allocateAndCopy(const char* source) {
    char* dest = new char[strlen(source) + 1];
    strcpy(dest, source);
    return dest;
}

Airplane::Airplane(int weightCapacity, int currentWeight, int fuelAmount, const char* model, State state)
    : weightCapacity(weightCapacity), currentWeight(currentWeight), fuelAmount(fuelAmount), state(state) {
    this->model = allocateAndCopy(model);
}

// Copy Constructor
Airplane::Airplane(const Airplane& other)
    : weightCapacity(other.weightCapacity), currentWeight(other.currentWeight), fuelAmount(other.fuelAmount), state(other.state) {
    model = allocateAndCopy(other.model);
}

Airplane::~Airplane() {
    delete[] model;
}

Airplane& Airplane::operator=(const Airplane& other) {
    if (this == &other) return *this; // Self-assignment check

    // Clean up existing resources
    delete[] model;

    // Allocate new resources and copy
    weightCapacity = other.weightCapacity;
    currentWeight = other.currentWeight;
    fuelAmount = other.fuelAmount;
    model = allocateAndCopy(other.model);
    state = other.state;

    return *this;
}

int Airplane::getWeightCapacity() const {
    return weightCapacity;
}

void Airplane::setWeightCapacity(int weightCapacity) {
    this->weightCapacity = weightCapacity;
}

int Airplane::getCurrentWeight() const {
    return currentWeight;
}

void Airplane::setCurrentWeight(int currentWeight) {
    this->currentWeight = currentWeight;
}

int Airplane::getFuelAmount() const {
    return fuelAmount;
}

void Airplane::setFuelAmount(int fuelAmount) {
    this->fuelAmount = fuelAmount;
}

const char* Airplane::getModel() const {
    return model;
}

void Airplane::setModel(const char* model) {
    delete[] this->model;
    this->model = allocateAndCopy(model);
}

Airplane::State Airplane::getState() const {
    return state;
}

void Airplane::setState(State state) {
    this->state = state;
}

void Airplane::display() const {
    std::cout << "Model: " << model << std::endl;
    std::cout << "Weight Capacity: " << weightCapacity << " kg" << std::endl;
    std::cout << "Current Weight: " << currentWeight << " kg" << std::endl;
    std::cout << "Fuel Amount: " << fuelAmount << " liters" << std::endl;
    std::cout << "State: " << (state == Taxi ? "Taxi" : state == Landing ? "Landing" : state == Takeoff ? "Takeoff" : "Parked") << std::endl;
}

#endif // !_AIRPLANE_H
