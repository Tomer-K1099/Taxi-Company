#ifndef DELIVERYFACADE_H
#define DELIVERYFACADE_H

#include "TaxiCompany.h"

class DeliveryFacade {
public:
    void displayMenu(TaxiCompany& company) {
        int option;
        bool stop = false;

        do {
            std::cout << "Delivery Management Menu:" << std::endl;
            std::cout << "[1] - Add Delivery" << std::endl;
            std::cout << "[2] - Print All Deliveries" << std::endl;
            std::cout << "[3] - Remove a Delivery" << std::endl;

            std::cout << "[-1] - Back to Main Menu" << std::endl;

            std::cin >> option;

            switch (option) {
            case 1:
                company.addDelivery();
                break;
            case 2:
                company.printDeliveries();
                break;
            case 3:
                company.removeDelivery();
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

#endif // DELIVERYFACADE_H
