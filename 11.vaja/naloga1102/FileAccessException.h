#include "exception"
#include "string"
#include "iostream"
#ifndef NALOGA1102_FILEACCESSEXCEPTION_H
#define NALOGA1102_FILEACCESSEXCEPTION_H


class FileAccessException : public std::exception{
private:
    std::string message;
public:
    FileAccessException(const std::string& fileName);

    const char* what() const throw();
};


#endif //NALOGA1102_FILEACCESSEXCEPTION_H
