#ifndef NALOGA1101_DUPLICATEDSENSORIDEXEPTION_H
#define NALOGA1101_DUPLICATEDSENSORIDEXEPTION_H
#include "iostream"
#include "string"
#include "exception"

class DuplicatedSensorIdExeption : public std::exception {
private:
    std::string message;
public:
    DuplicatedSensorIdExeption(int id);

    const char* what() const throw ();

};

#endif //NALOGA1101_DUPLICATEDSENSORIDEXEPTION_H
