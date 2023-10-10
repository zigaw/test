//
// Created by weing on 27/03/2023.
//

#include "SavingAccount.h"


SavingAccount::SavingAccount(unsigned int number, double balance, Person *owner, double interestRate) : Account(number,
                                                                                                                balance,
                                                                                                                owner),
                                                                                                        interestRate(
                                                                                                                interestRate),
                                                                                                        lastWithdrawalDate(
                                                                                                                0, 0,
                                                                                                                0) {}

double SavingAccount::getInterestRate() const {
    return interestRate;
}

void SavingAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}


std::string SavingAccount::toString() {
    std::stringstream savingAccountData;
    savingAccountData << "Owner: " << owner->toString() << std::endl;
    savingAccountData << "Number: " << std::to_string(number) << std::endl;
    savingAccountData << "Balance: " << std::to_string(balance) << std::endl;
    savingAccountData << "Interest rate: " << std::to_string(interestRate) << std::endl;
    savingAccountData << "Last withdrawal date: " << lastWithdrawalDate.toString() << std::endl;
    return savingAccountData.str();
}

bool SavingAccount::makeDeposit(double &amount) {
    if (amount > 0) {
        balance += amount + amount * (interestRate / 100);
        return true;
    } else {
        return false;
    }
}

bool SavingAccount::makeWithdrawal(double &amount) {
    if (amount > 0) {
        unsigned int timeBetweenWithdrawals = Date::getDifferenceDays(Date::getCurrentDate(), lastWithdrawalDate);
        if (timeBetweenWithdrawals > 90) {
            balance -= amount - amount * (interestRate / 100);
            lastWithdrawalDate = Date::getCurrentDate();

            return true;
        }
    } else {
        return false;
    }
}