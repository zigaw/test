#ifndef NALOGA0502_TRANSACTION_H
#define NALOGA0502_TRANSACTION_H
#include "Account.h"
#include "Date.h"
class Transaction {
private:
    unsigned int accountNumber;
    Date date;
    double amount;
public:

    Transaction(unsigned int accountNumber, const Date &date, double amount);

    unsigned int getAccountNumber() const;

    void setAccountNumber(unsigned int accountNumber);

    const Date &getDate() const;

    void setDate(const Date &date);

    double getAmount() const;

    void setAmount(double amount);

    std::string toString();

};


#endif //NALOGA0502_TRANSACTION_H
