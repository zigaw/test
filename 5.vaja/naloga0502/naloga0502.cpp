#include "SavingAccount.h"


using namespace std;

int main() {

    double interestRate = 4;
    double amount1 = 60600;
    double amount2 = -300;
    Person *person1 = new Person("Bill", "Gates");
    Person *person2 = new Person("Mark", "Zuckerberg");
    Person *person3 = new Person("Jeff", "Bezos");

    Account *account1 = new Account(0, 103400000000, person1);
    Account *account2 = new Account(1, 171000000, person2);
    Account *account3 = new Account(2, 121200000000, person3);

    SavingAccount *savingAccount3 = new SavingAccount(3, 121200000000, person3, interestRate);


    account2->makeDeposit(amount1);

    savingAccount3->makeWithdrawal(amount2);
    savingAccount3->makeWithdrawal(amount1);

    cout << to_string(savingAccount3->getBalance()) << endl << endl;


    Bank bank1;
    bank1.addAccount(account1);
    bank1.addAccount(account2);
    bank1.addAccount(account3);
    bank1.addAccount(savingAccount3);
    bank1.makeWithdrawalOnAccount(500000,1);
    bank1.makeDepositOnAccount(12345678,0);

    cout << bank1.toString();


    delete person1;
    delete person2;
    delete person3;

    return 0;
}