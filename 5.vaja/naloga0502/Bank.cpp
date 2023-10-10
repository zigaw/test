#include "Bank.h"

Bank::Bank() {}

Bank::~Bank() {
    for (int i = 0; i < accounts.size(); ++i) {
        delete accounts[i];
    }
}

void Bank::addAccount(Account *account) {
    accounts.push_back(account);
}

bool Bank::makeDepositOnAccount(double amount, unsigned int accountNumber) {
    if (findAccount(accountNumber)->getNumber() == accountNumber) {
        if(findAccount(accountNumber)->makeDeposit(amount)) {
            findAccount(accountNumber)->makeDeposit(amount);
            Transaction transaction(accountNumber, Date::getCurrentDate(), amount);
            transactions.push_back(transaction);
            return true;
        }
    } else {
        return false;
    }
}


bool Bank::makeWithdrawalOnAccount(double amount, unsigned int accountNumber) {
    if (findAccount(accountNumber)->getNumber() == accountNumber) {
        if(findAccount(accountNumber)->makeDeposit(amount)) {
            findAccount(accountNumber)->makeWithdrawal(amount);
            Transaction transaction(accountNumber, Date::getCurrentDate(), -amount);
            transactions.push_back(transaction);
            return true;
        }
    } else {
        return false;
    }

}


std::string Bank::toString() {
    std::stringstream bankData;
    bankData << "All bank accounts: " << std::endl << std::endl;
    for (int i = 0; i < accounts.size(); i++) {
        bankData << accounts[i]->toString();
    }
    return bankData.str();
}

Account* Bank::findAccount(unsigned int accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i]->getNumber() != accountNumber) {
        } else {
            return accounts[i];
        }
    }
    return accounts[0];
}

void Bank::printTransaction() {
    for (int i = 0; i < transactions.size(); i++) {
        transactions[i].toString();
    }
}