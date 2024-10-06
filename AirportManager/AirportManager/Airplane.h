#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <cstring>
class Airline;
class Runway;

class Airplane {
public:

    friend class Airport; //friend to allow Airport access Runway pointer 

    // Enum for the state of the airplane
    enum State {
        QueuedLanding,
        Landing,
        Taxi,
        Takeoff,
        QueuedTakeoff,
        Parked,
    };

protected:
    const int serialNum;
    const int weightCapacity;
    int currentWeight;
    const char* model;
    State state;
    Airline& belongsTo;  //which airline does this plane belong to 
    const Runway* assignedTo; //which runway was this plane assigned to (only address is mutable) - can be null


    // Helper function to allocate and copy string
    char* allocateAndCopy(const char* source);

public:
    Airplane(const int serialnum, const int weightCapacity, const char* model, const State state, Airline& belongs, const int currentWeight = 0 , const Runway* assinged = nullptr);

    Airplane(const Airplane& other);

    ~Airplane();

    Airplane& operator=(const Airplane& other); //Assingment operator

    int getWeightCapacity() const;
    void setWeightCapacity(int weightCapacity);

    int getCurrentWeight() const;
    void setCurrentWeight(int currentWeight);

    const char* getModel() const;
    void setModel(const char* model);

    State getState() const;
    void setState(State state);

    Airline& getBelongsTo() const;
    void setBelongsTo(Airline& belongsTo);

    virtual void display() const;
};

#endif 
