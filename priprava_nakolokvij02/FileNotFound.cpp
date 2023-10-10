
#include "FileNotFound.h"

const char* FileNotFound:: what() const noexcept{
    return message.c_str();
}

FileNotFound:: FileNotFound(std::string fileName){
    message = "File " + fileName + " not fount!";
}