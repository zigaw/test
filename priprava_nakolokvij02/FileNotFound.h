#include "iostream"
#include "string"
#include "exception"
#ifndef PRIPRAVA_NAKOLOKVIJ02_FILENOTFOUND_H
#define PRIPRAVA_NAKOLOKVIJ02_FILENOTFOUND_H


class FileNotFound :public std::exception{
private:
    std::string message;
public:
    const char* what() const noexcept override;

    FileNotFound(std::string fileName);
};


#endif //PRIPRAVA_NAKOLOKVIJ02_FILENOTFOUND_H
