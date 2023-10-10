#ifndef NALOGA0502_ACCOUNT_H
#define NALOGA0502_ACCOUNT_H
#include "Person.h"

class Account {
protected:
    Person *owner;
    unsigned int number;
    double balance;
public:
    Account(unsigned int number, double balance, Person *owner);

    unsigned int getNumber() const;

    void setNumber(unsigned int number);

    double getBalance() const;

    void setBalance(double balance);

    virtual std::string toString();

   virtual bool makeDeposit(double &amount);

    virtual bool makeWithdrawal(double &amount);
};
#endif //NALOGA0502_ACCOUNT_H
