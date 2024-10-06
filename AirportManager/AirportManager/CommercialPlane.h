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
    CommercialPlane(const int weightCapacity, const int currentWeight, const char* model, const State state,
        const int numOfSeats, const int actualSeatsOccupied=0, const int totalBaggageWeight=0);

    CommercialPlane(const CommercialPlane& other);

    ~CommercialPlane();

    //operators
    CommercialPlane& operator=(const CommercialPlane& other);
    friend std::ostream& operator<<(std::ostream& os, const CommercialPlane& plane); /*Print operator*/

    //getters setters
    int getNumOfSeats() const;
    void setNumOfSeats(int numOfSeats);

    int getActualSeatsOccupied() const;
    void setActualSeatsOccupied(int actualSeatsOccupied);

    int getTotalBaggageWeight() const;
    void setTotalBaggageWeight(int totalBaggageWeight);

    void occupyASeat();

    void addBaggage(int baggageWeight);

    void display() const override;

};


#endif // !_COMMERCIALPLANE_H
