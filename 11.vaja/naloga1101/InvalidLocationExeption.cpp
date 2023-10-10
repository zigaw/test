#include "InvalidLocationExeption.h"

InvalidLocationExeption:: InvalidLocationExeption(int id){
    counterOfExceprions++;
    message = "Invalid location on sensor id: " + std::to_string(id) + " exception number: "+ std::to_string(counterOfExceprions) + "\n";
}

 const char* InvalidLocationExeption:: what() const throw (){
     return message.c_str();
}