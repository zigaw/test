
#include "UnparsableDateException.h"

const  char* UnparsableDateException:: what() const noexcept{
    return message.c_str();
}

UnparsableDateException::UnparsableDateException(std::string wrongDate){
    message = wrongDate;
}