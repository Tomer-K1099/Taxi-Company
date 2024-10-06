#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <string>  



enum PaymentOption { Credit, Cash, NofOpt };


class Payment {

private:
    PaymentOption option;
    int price;

public:
    // Constructors
    Payment(PaymentOption opt = Cash, int p=0);

	bool operator==(const Payment& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Payment& payment);

    // Getters
    PaymentOption getOption() const;
    int getPrice() const;

    // Setters
    bool setOption(const PaymentOption opt);
    bool setPrice(const int price);

	
};

#endif // PAYMENT_H

