#ifndef NALOGA0402_USER_H
#define NALOGA0402_USER_H

#include <sstream>
#include <string>
#include <iostream>

class User {
private:
    std::string firstName;
    std::string lastName;
    std::string address;

public:
    User(const std::string &firstName, const std::string &lastName, const std::string &address);

    std::string toString();

    std::string getFirstName();

    std::string getLastName();

    std::string getAddress();

    void setFirstName(std::string setFirstName);

    void setLastName(std::string setLastName);

    void setAddress(std::string setAddress);


};


#endif //NALOGA0402_USER_H
