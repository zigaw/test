//
// Created by weing on 27/03/2023.
//

#include "Account.h"

Account::Account(unsigned int number, double balance, Person *owner) : number(number), balance(balance), owner(owner) {}

unsigned int Account::getNumber() const {
    return this->number;
}

void Account::setNumber(unsigned int number) {
    this->number = number;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

std::string Account::toString() {
    std::stringstream accountData;
    accountData << "Owner: " << owner->toString() << std::endl;
    accountData << "Number: " << std::to_string(number) << std::endl;
    accountData << "Balance: " << std::to_string(balance) << std::endl << std::endl;
    return accountData.str();
}


bool Account::makeDeposit(double &amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    } else {
        return false;
    }
}

bool Account::makeWithdrawal(double &amount) {
    if (amount > 0) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

