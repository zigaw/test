//
// Created by weing on 27/03/2023.
//

#ifndef NALOGA0502_PERSON_H
#define NALOGA0502_PERSON_H

#include "iostream"
#include "string"
#include "sstream"

class Person {
private:
    std::string firstName;
    std::string lastName;
public:
    Person(const std::string &firstName, const std::string &lastName);


    std::string toString();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);
};


#endif //NALOGA0502_PERSON_H
