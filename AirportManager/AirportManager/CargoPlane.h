#ifndef CARGOPLANE_H
#define CARGOPLANE_H
/* A cargo plane is a plane that carries different goods.Perishable, Live Animals, and Hazardous  
   cargo types require temperature control, while Non perishable and oversized don't.*/
#include "Airplane.h"

class CargoPlane : public Airplane {
public:
    // Enum for the type of cargo
    enum CargoType {
        Perishable,
        NonPerishable,
        Hazardous,
        LiveAnimals,
        Oversized
    };

private:
    bool temperatureControlled;
    CargoType cargoType;

public:
    CargoPlane(const int weightCapacity, const int currentWeight, const char* model, State state,
        bool temperatureControlled, CargoType cargoType);

    CargoPlane(const CargoPlane& other);

    ~CargoPlane();

    // Assignment Operator
    CargoPlane& operator=(const CargoPlane& other);
    friend std::ostream& operator<<(std::ostream& os, const CargoPlane& plane); /*Print operator*/

    bool isTemperatureControlled() const;
    void setTemperatureControlled(const bool temperatureControlled);

    CargoType getCargoType() const;
    void setCargoType(CargoType cargoType);

    void display() const override;

    void addCargo();
    void addCargo(CargoType cargoType, int cargoWeight); //overloading
};

#endif