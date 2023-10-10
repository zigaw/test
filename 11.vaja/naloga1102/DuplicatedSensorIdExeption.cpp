#include "DuplicatedSensorIdExeption.h"

DuplicatedSensorIdExeption:: DuplicatedSensorIdExeption(int id){
    message = "Duplicated sensor id: " + std::to_string(id) + "\n";
}



const char* DuplicatedSensorIdExeption:: what() const throw () {
        return message.c_str();
}