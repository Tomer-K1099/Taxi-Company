#ifndef TAXIFACADE_H
#define TAXIFACADE_H

#include "TaxiCompany.h"

class TaxiFacade {
public:
    void displayMenu(TaxiCompany& company) {
        int option;
        bool stop = false;

        do {
            std::cout << "Taxi Management Menu:" << std::endl;
            std::cout << "[1] - Add Taxi" << std::endl;
            std::cout << "[2] - Print All Taxis" << std::endl;
            std::cout << "[3] - Remove a Taxi" << std::endl;

            std::cout << "[-1] - Back to Main Menu" << std::endl;

            std::cin >> option;

            switch (option) {
            case 1:
                company.addTaxi();
                break;
            case 2:
                company.printTaxis();
                break;
            case 3: 
                company.removeTaxi();
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

#endif // TAXIFACADE_H
