#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <cstring>

class Airplane {
public:
    // Enum for the state of the airplane
    enum State {
        Taxi,
        Landing,
        Takeoff,
        Parked
    };

protected:
    int weightCapacity;
    int currentWeight;
    int fuelAmount;
    char* model;
    State state;



public:
    Airplane(int weightCapacity, int currentWeight, int fuelAmount, const char* model, State state);

    // Copy Constructor
    Airplane(const Airplane& other);

    ~Airplane();

    // Assignment Operator
    Airplane& operator=(const Airplane& other);

    int getWeightCapacity() const;
    void setWeightCapacity(int weightCapacity);

    int getCurrentWeight() const;
    void setCurrentWeight(int currentWeight);

    int getFuelAmount() const;
    void setFuelAmount(int fuelAmount);

    const char* getModel() const;
    void setModel(const char* model);

    State getState() const;
    void setState(State state);

    virtual void display() const;
};

#endif 
