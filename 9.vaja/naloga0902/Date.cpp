#include "Date.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}

unsigned int Date::getDay() const {
    return day;
}

void Date::setDay(unsigned int day) {
    Date::day = day;
}

unsigned int Date::getMonth() const {
    return month;
}

void Date::setMonth(unsigned int month) {
    Date::month = month;
}

unsigned int Date::getYear() const {
    return year;
}

void Date::setYear(unsigned int year) {
    Date::year = year;
}

std::string Date::toString() const {
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}

std::ostream& operator<<(std::ostream &out, const Date &date) {
    out << date.toString();
    return out;
}

bool Date::operator==(const Date& other) const{
    if(this->getDay() != other.getDay()){
        return 0;
    }else if(this->getMonth() != other.getMonth()){
        return 0;
    }else if (this->getYear() != other.getYear()){
        return 0;
    }
    return 1;
};


Date& Date::operator++() {
    day++;
    if (day > months[month-1]) {
        day = 1;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator++(int dummy)  {
    Date tmp(*this);
    operator++();
    return tmp;
}