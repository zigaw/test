#ifndef NALOGA0502_BANK_H
#define NALOGA0502_BANK_H

#include "Account.h"
#include "vector"
#include "Transaction.h"
class Bank {
private:
    std::vector<Transaction>transactions;
    std::vector<Account*> accounts;
public:
    Bank();

    void addAccount(Account *account);

    bool makeDepositOnAccount(double amount, unsigned int accountNumber);

    bool makeWithdrawalOnAccount(double amount, unsigned int accountNumber);

    std::string toString();

    virtual ~Bank();

    Account* findAccount(unsigned int accountNumber);

    void printTransaction();

};


#endif //NALOGA0502_BANK_H
