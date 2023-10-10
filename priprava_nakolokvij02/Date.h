#include "UnparsableDateException.h"
#include "sstream"
#ifndef PRIPRAVA_NAKOLOKVIJ02_DATE_H
#define PRIPRAVA_NAKOLOKVIJ02_DATE_H


class Date {
private:
    unsigned int day,month,year;
public:
    Date(unsigned int day,unsigned int mont,unsigned int year);

    unsigned int getDay() const;

    unsigned int getMonth() const;

    unsigned int getYear() const;

    std::string toString() const;

    Date static getDateFromStrinf(std::string date){
        int dot = 0;
        bool charE = false;
        for (int i = 0; i < date.size(); ++i) {
            if (date[i] == '.'){
                dot++;
            } else if(date[i] < '0' || date[i] > '9'){
                charE = true;
            }
        }
        if(dot != 2 && charE){
            throw UnparsableDateException(date) ;
        } else{
           unsigned int day = std::stoi(date.substr(0, 2));
          unsigned  int month = std::stoi(date.substr(3, 2));
           unsigned int year = std::stoi(date.substr(6));
           Date date1(day,month,year);
            return date1;
        }
    }
};


#endif //PRIPRAVA_NAKOLOKVIJ02_DATE_H
