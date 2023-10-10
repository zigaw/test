#include "FileAccessException.h"

FileAccessException::FileAccessException(const std::string &fileName) {
    message = "Error with opening file: " + fileName + "\n";
}

const char* FileAccessException::what() const throw() {
    return message.c_str();
}