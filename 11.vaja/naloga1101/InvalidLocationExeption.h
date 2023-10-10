#include "iostream"
#include "string"
#include "exception"
#ifndef NALOGA1101_INVALIDLOCATIONEXEPTION_H
#define NALOGA1101_INVALIDLOCATIONEXEPTION_H


class InvalidLocationExeption :public std::exception{
private:
    std::string message;

public:
    static int counterOfExceprions;

    InvalidLocationExeption(int id);

    const char* what() const throw ();

};


#endif //NALOGA1101_INVALIDLOCATIONEXEPTION_H
