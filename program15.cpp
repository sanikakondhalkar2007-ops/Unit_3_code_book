#include <iostream>                                      // Includes the iostream library for input and output
#include <string>                                        // Includes the string library for string operations

class Payment                                             // Defines the abstract base class Payment
{
public:                                                   // Starts the public section of Payment

    virtual void pay(double amount) const = 0;            // Declares pure virtual pay() function

    virtual ~Payment() = default;                         // Defines a virtual destructor
};

class CardPayment : public Payment                         // Defines CardPayment class inheriting from Payment
{
public:                                                   // Starts the public section of CardPayment

    void pay(double amount) const override                 // Overrides the pay() function for card payment
    {
        std::cout << "Paid Rs. " << amount << " using card\n"; // Displays the card payment message
    }
};

class UpiPayment : public Payment                          // Defines UpiPayment class inheriting from Payment
{
public:                                                   // Starts the public section of UpiPayment

    void pay(double amount) const override                 // Overrides the pay() function for UPI payment
    {
        std::cout << "Paid Rs. " << amount << " using UPI\n"; // Displays the UPI payment message
    }
};

class NetBankingPayment : public Payment                   // Defines NetBankingPayment class inheriting from Payment
{
public:                                                   // Starts the public section of NetBankingPayment

    void pay(double amount) const override                 // Overrides the pay() function for net banking payment
    {
        std::cout << "Paid Rs. " << amount << " using net banking\n"; // Displays the net banking payment message
    }
};

void processPayment(const Payment& payment, double amount) // Defines a function to process any payment type
{
    payment.pay(amount);                                    // Calls the correct payment function using runtime polymorphism
}

int main()                                                 // Main function where program execution starts
{
    CardPayment card;                                      // Creates a CardPayment object

    UpiPayment upi;                                        // Creates a UpiPayment object

    NetBankingPayment netBanking;                          // Creates a NetBankingPayment object

    processPayment(card, 1250.0);                         // Processes a payment of Rs. 1250 using card

    processPayment(upi, 750.0);                            // Processes a payment of Rs. 750 using UPI

    processPayment(netBanking, 500.0);                    // Processes a payment of Rs. 500 using net banking

    return 0;                                              // Returns 0 to indicate successful execution
}