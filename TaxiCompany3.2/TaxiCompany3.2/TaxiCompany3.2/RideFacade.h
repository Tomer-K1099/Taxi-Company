#ifndef RIDEFACADE_H
#define RIDEFACADE_H

#include "TaxiCompany.h"

class RideFacade {
public:
    void displayMenu(TaxiCompany& company) {
        int option;
        bool stop = false;

        do {
            std::cout << "Ride Management Menu:" << std::endl;
            std::cout << "[1] - Add Ride" << std::endl;
            std::cout << "[2] - Print All Rides" << std::endl;
            std::cout << "[-1] - Back to Main Menu" << std::endl;

            std::cin >> option;

            switch (option) {
            case 1:
                try {
                    company.addRide();
                }
                catch (const std::string& msg) {
                    std::cout << "Error: " << msg << std::endl;
                }
                break;
            case 2:
                company.printRides();
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

#endif // RIDEFACADE_H
