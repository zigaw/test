#include "Person.h"

Person::Person(const std::string &firstName, const std::string &lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}


const std::string &Person::getFirstName() const {
    return firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
}

void Person::setLastName(const std::string &lastName) {
    this->lastName = lastName;
}

std::string Person::toString() {
    std::stringstream stringPersonData;
    stringPersonData << firstName << " " << lastName;
    return stringPersonData.str();
}