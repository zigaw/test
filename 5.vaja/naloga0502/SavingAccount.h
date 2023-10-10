#ifndef NALOGA0502_SAVINGACCOUNT_H
#define NALOGA0502_SAVINGACCOUNT_H

#include "Date.h"
#include "Bank.h"

class SavingAccount : public Account {
private:
    double interestRate;
    Date lastWithdrawalDate;
public:
    SavingAccount(unsigned int number, double balance, Person *owner, double interestRate);

    std::string toString() override;

    double getInterestRate() const;

    void setInterestRate(double interestRate);

    bool makeDeposit(double &amount) override;

    bool makeWithdrawal(double &amount) override;
};


#endif //NALOGA0502_SAVINGACCOUNT_H
