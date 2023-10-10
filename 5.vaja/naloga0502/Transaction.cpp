#include "transaction.h"


Transaction::Transaction(unsigned int accountNumber, const Date &date, double amount) : accountNumber(accountNumber),date(date), amount(amount) {}
unsigned int Transaction::getAccountNumber() const {
    return accountNumber;
}

void Transaction::setAccountNumber(unsigned int accountNumber) {
    this->accountNumber = accountNumber;
}

const Date &Transaction::getDate() const {
    return date;
}

void Transaction::setDate(const Date &date) {
    this->date = date;
}

double Transaction::getAmount() const {
    return amount;
}

void Transaction::setAmount(double amount) {
    this->amount = amount;
}


std::string Transaction::toString() {

    std::stringstream transactionData;
    transactionData << "accountNumber: " << std::to_string(accountNumber) << std::endl;
    transactionData << "Date: " <<  date.toString() << std::endl;
    transactionData << "Amount: " << std::to_string(amount) << std::endl << std::endl;
    return transactionData.str();
}
