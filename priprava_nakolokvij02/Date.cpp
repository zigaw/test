
#include "Date.h"

Date::Date(unsigned int day, unsigned int mont, unsigned int year):day(day),month(mont),year(year) {
}

unsigned int Date::getDay() const {
    return day;
}

unsigned int Date::getMonth() const {
    return month;
}

unsigned int Date::getYear() const {
    return year;
}

std::string Date:: toString() const{
    std::stringstream  dateString;
    if(this->getDay()<10){
        dateString << "0";
    }
    dateString << std::to_string(this->getDay()) << ".";
    if(this->getMonth()<10){
        dateString << "0";
    }
    dateString << std::to_string(this->getMonth()) << ".";
    dateString << std::to_string(this->getYear());
    return dateString.str();
}