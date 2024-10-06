#ifndef DRIVERFACADE_H
#define DRIVERFACADE_H

#include "TaxiCompany.h"

class DriverFacade {
public:
    void displayMenu(TaxiCompany& company) {
        int option;
        bool stop = false;

        do {
            std::cout << "Driver Management Menu:" << std::endl;
            std::cout << "[1] - Add Driver" << std::endl;
            std::cout << "[2] - Print All Drivers" << std::endl;
            std::cout << "[3] - Remove a Driver" << std::endl;

            std::cout << "[-1] - Back to Main Menu" << std::endl;

            std::cin >> option;

            switch (option) {
            case 1:
                company.addDriver();
                break;
            case 2:
                company.printDrivers();
                break;
            case 3:
                company.removeDriver();
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

#endif // DRIVERFACADE_H
