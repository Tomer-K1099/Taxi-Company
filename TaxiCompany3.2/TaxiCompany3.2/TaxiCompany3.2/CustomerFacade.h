#ifndef CUSTOMERFACADE_H
#define CUSTOMERFACADE_H

#include "TaxiCompany.h"

class CustomerFacade {
public:
    void displayMenu(TaxiCompany& company) {
        int option;
        bool stop = false;

        do {
            std::cout << "Customer Management Menu:" << std::endl;
            std::cout << "[1] - Add Customer" << std::endl;
            std::cout << "[2] - Print All Customers" << std::endl;
            std::cout << "[3] - Remove Customer" << std::endl;
            std::cout << "[-1] - Back to Main Menu" << std::endl;

            std::cin >> option;

            switch (option) {
            case 1:
                company.addCustomer();
                break;
            case 2:
                company.printCustomers();
                break;
            case 3: 
                company.removeCustomer();
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

#endif // CUSTOMERFACADE_H
