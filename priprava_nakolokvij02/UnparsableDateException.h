
#ifndef PRIPRAVA_NAKOLOKVIJ02_UNPARSABLEDATEEXCEPTION_H
#define PRIPRAVA_NAKOLOKVIJ02_UNPARSABLEDATEEXCEPTION_H
#include "iostream"
#include "exception"
#include "string"

class UnparsableDateException: public std::exception{
private:
    std::string message;
public:
    const char* what() const noexcept override;

    UnparsableDateException(std::string wrongDate);

};


#endif //PRIPRAVA_NAKOLOKVIJ02_UNPARSABLEDATEEXCEPTION_H
