#include "User.h"


User::User(const std::string &firstName, const std::string &lastName, const std::string &address) {}


std::string User::toString() {
    std::stringstream userData;
    userData << "First name: " << firstName << std::endl;
    userData << "Last name: " << lastName << std::endl;
    userData << "Address: " << address << std::endl;
}


std::string User::getAddress() {
    return this->address;
}

std::string User::getFirstName() {
    return this->firstName;
}

std::string User::getLastName() {
    return this->lastName;
}


void User::setAddress(std::string setAddress) {
    address = setAddress;
}

void User::setFirstName(std::string setFirstName) {
    firstName = setFirstName;
}

void User::setLastName(std::string setLastName) {
    lastName = setLastName;
}












