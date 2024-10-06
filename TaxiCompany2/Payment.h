#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>


enum PaymentOption { Credit, Cash, NofOpt };

//const char* OptStr[NofOpt] = { "Credit", "Cash" };

class Payment {

private:
    PaymentOption option;
    int price;

public:
    // Constructors
    Payment(PaymentOption opt, int p);

	bool operator==(const Payment& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Payment& payment);

    // Getters
    const PaymentOption getOption() const;
    const int getPrice() const;

    // Setters
    bool setOption(const PaymentOption opt);
    bool setPrice(const int price);
};

#endif // PAYMENT_H

