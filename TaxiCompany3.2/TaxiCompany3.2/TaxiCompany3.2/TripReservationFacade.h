#ifndef TRIPRESERVATIONFACADE_H
#define TRIPRESERVATIONFACADE_H

#include "TaxiCompany.h"

class TripReservationFacade {
public:
    void displayMenu(TaxiCompany& company) {
        int option;
        bool stop = false;

        do {
            std::cout << "Trip Reservation Management Menu:" << std::endl;
            std::cout << "[1] - Add Trip Reservation" << std::endl;
            std::cout << "[2] - Print All Trip Reservations" << std::endl;
            std::cout << "[3] - Remove a Trip Reservation" << std::endl;

            std::cout << "[-1] - Back to Main Menu" << std::endl;

            std::cin >> option;

            switch (option) {
            case 1:
                try {
                    company.addTripReservation();
                }
                catch (const std::string& msg) {
                    std::cout << "Error: " << msg << std::endl;
                }
                break;
            case 2:
                company.printTripReservations();
                break;
            case 3:
                company.removeTripReservation();
                break;
            case -1:
                stop = true;
                break;
            default:
                std::cout << "Invalid option, try again." << std::endl;
            }
        } while (!stop);
    }
};

#endif // TRIPRESERVATIONFACADE_H
