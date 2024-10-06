#ifndef _COMMERCIALPLANE_H
#define _COMMERCIALPLANE_H
#include "Airplane.h"
class CommercialPlane :
	public Airplane
{
private:
    int numOfSeats;
    int actualSeatsOccupied;
    int totalBaggageWeight;

public:
    CommercialPlane(int weightCapacity, int currentWeight, int fuelAmount, const char* model, State state,
        int numOfSeats, int actualSeatsOccupied, int totalBaggageWeight);

    CommercialPlane(const CommercialPlane& other);

    ~CommercialPlane();

    CommercialPlane(CommercialPlane&& other);

    CommercialPlane& operator=(const CommercialPlane& other);

    int getNumOfSeats() const;
    void setNumOfSeats(int numOfSeats);

    int getActualSeatsOccupied() const;
    void setActualSeatsOccupied(int actualSeatsOccupied);

    int getTotalBaggageWeight() const;
    void setTotalBaggageWeight(int totalBaggageWeight);

    void occupyASeat();

    void addBaggage(int baggageWeight);

    void display() const override;

    friend std::istream& operator>>(std::istream& in, CommercialPlane p)
    {
        in >> p.numOfSeats >> p.actualSeatsOccupied >> p.totalBaggageWeight;
    }

};


#endif // !_COMMERCIALPLANE_H
