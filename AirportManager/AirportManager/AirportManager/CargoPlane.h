#ifndef CARGOPLANE_H
#define CARGOPLANE_H

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
    CargoPlane(int weightCapacity, int currentWeight, int fuelAmount, const char* model, State state,
        bool temperatureControlled, CargoType cargoType);

    CargoPlane(const CargoPlane& other);

    ~CargoPlane();

    // Assignment Operator
    CargoPlane& operator=(const CargoPlane& other);

    bool isTemperatureControlled() const;
    void setTemperatureControlled(bool temperatureControlled);

    CargoType getCargoType() const;
    void setCargoType(CargoType cargoType);

    void display() const override;

    // Methods to add cargo
    void addCargo();
    void addCargo(CargoType cargoType, int cargoWeight);
};

#endif